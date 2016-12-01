import os
import sys
import subprocess
import logging
import tempfile

import thread

YPLS_EXE = r"D:\Projects\YaraGithub\yara\windows\vs2015\Debug\ypls64.exe"
LOGGER = logging.getLogger(__name__)

# file for testing yara rules
TEST_FILE = "YPLS test file"
# yara rules that must match yara test file
TEST_RULE = 'rule test {strings: $str0 = "YPLS test file" condition: all of them}\n'


class YplsError(Exception):
    pass


def get_temp_file():
    """ Reserve file name in temp folder """
    (fd, temp_file) = tempfile.mkstemp()
    os.close(fd)
    return temp_file


class Ypls:

    def __init__(self, rules, variables=None, print_strings=False, timeout=None, ypls_exe=None, max_str_matches=sys.maxsize, safe=False):
        """
        Create instance of ypls scanner. Use scan, get_result and wait methods to work with it.

        Args:
          rules (string) - path to file with yara rules
          variables (dict) - external variables to use (see yara external variables in yara documentation)
          print_strings (bool) - print strings? See -s option in yara documentation
          timeout (int) - yara scan timeout. See -a option in yara documentation
          ypls_exe (string) - path to ypls executable
          max_str_matches (int) - max number of strings to return (per variable). Used only if print_strings=True
        """
        self.rules = os.path.abspath(rules)
        self.variables = dict(variables) if variables else dict()
        self.print_strings = print_strings
        self.ypls_exe = ypls_exe if ypls_exe else YPLS_EXE
        self.timeout = timeout
        self.max_str_matches = max_str_matches
        self.safe = safe
        self.proc = None

    def __enter__(self):
        self.start()
        return self

    def __exit__(self, exc_type, exc, tb):
        self.close()

    def is_running(self):
        # process is running if poll() returns None
        return self.proc and self.proc.poll() is None

    def close(self):
        if self.is_running():
            self.proc.communicate(b"Q")
            self.proc.wait()

        self.proc = None

    def start(self):
        if self.is_running():
            return

        LOGGER.debug("Starting scanner")
        args = [self.ypls_exe]
        if self.print_strings:
            args.append("-sL")

        if self.safe:
            args.append("--fail-on-warnings")

        for variable in self.variables:
            args.append("-d")
            args.append("{}={}".format(variable, self.variables[variable]))

        if self.timeout:
            args.append("-a")
            args.append(str(self.timeout))

        args.append(self.rules)
        self.proc = subprocess.Popen(args, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                                     stdin=subprocess.PIPE, creationflags=subprocess.CREATE_NEW_CONSOLE)

    def check_rules(self):
        """ Checks whether rules file with our added rule matches our test file. If not, raise exception. """
        test_rules = get_temp_file()
        test_file = get_temp_file()

        with open(self.rules, "r", encoding="ascii") as r, open(test_rules, "w") as tr, open(test_file, "w") as tf:
            tr.write(TEST_RULE + r.read())
            tf.write(TEST_FILE)

        found = False
        with Ypls(test_rules, self.variables, print_strings=False, ypls_exe=self.ypls_exe, safe=self.safe) as ypls:
            (matches, _) = ypls.scan_file(test_file)

        for (rule, _) in matches:
            if rule == "test":
                found = True
                break

        os.remove(test_rules)
        os.remove(test_file)

        if not found:
            raise YplsError("Invalid rules '{}'".format(self.rules))

    @staticmethod
    def _read_output_thread(file):
        thrd = thread.Thread(target=Ypls._read_lines, args=(file,))
        thrd.start()

        return thrd

    @staticmethod
    def _read_lines(file):
        lines = list()

        line = file.readline().decode("utf-8").strip()
        while line:
            lines.append(line)
            line = file.readline().decode("utf-8").strip()

        return lines

    def parse_output(self, stdout, stderr):
        """ Returns tuple (matches, stderr) where matches is a list of tuples [(rule, [strings], stderr), (rule, [strings], stderr)...] """
        if not stderr:
            stderr = None

        if not stdout:
            stdout = ""

        matches = list()
        strings = list()
        var_names = dict()
        rule = None

        for line in stdout:
            if line.startswith("0x"):  # it's a matched string
                line = line.lstrip()
                var_name = line.split(":", 3)[2]
                count = var_names.get(var_name, 0)
                if count < self.max_str_matches:
                    strings.append(line)
                    var_names[var_name] = count + 1
            else:  # it's a match
                if rule:
                    matches.append((rule, strings if strings else None))
                    strings = list()
                    var_names = dict()

                rule = line.split(" ", 1)[0]

        if rule:
            matches.append((rule, strings if strings else None))

        return (matches, stderr)

    def _write(self, cmd):
        if isinstance(cmd, str):
            cmd = cmd.encode("utf-8")

        self.proc.stdin.write(cmd)
        self.proc.stdin.flush()

    def is_ready(self, timeout):
        if not self.is_running():
            return False

        try:
            self._write("R")
            stdout = self._read_output_thread(self.proc.stdout)
            stderr = self._read_output_thread(self.proc.stderr)

            stdout = stdout.join(timeout, True)
            stderr = stderr.join(timeout, True)
            return stdout and stdout[0] == "READY"
        except (OSError, TimeoutError):
            return False

    def _scan(self, command, data=None, variables=None):
        self._write(command)

        if data:
            self._write(data)

        # copy self.variables and set them new values
        var = dict(self.variables)
        if variables:
            for variable in variables:
                if variable in var:
                    var[variable] = variables[variable]

        for variable in var:
            self._write("{}={}\n".format(variable, var[variable]))

        self._write("\n")

        stdout = self._read_output_thread(self.proc.stdout)
        stderr = self._read_output_thread(self.proc.stderr)

        return self.parse_output(stdout.join(self.timeout, True), stderr.join(self.timeout, True))

    def scan_process(self, pid, variables=None):
        return self._scan("P{}\n".format(pid), variables=variables)

    def scan_data(self, data, variables=None):
        assert isinstance(data, bytes)
        return self._scan("D{}\n".format(len(data)), data, variables)

    def scan_file(self, file, variables=None):
        return self._scan("F{}\n".format(file), variables=variables)


def test():
    ypls_exe = r"D:\Projects\YaraGithub\yara\windows\vs2015\Debug\ypls64.exe"
    variables = {"threat": str(None), "source": "file", "parent_threat": str(None)}
    with open(ypls_exe, "rb") as f:
        data = f.read()

    with Ypls(r"D:\Projects\YaraGithub\yara\sample.rules", variables, print_strings=True, timeout=60, ypls_exe=ypls_exe, safe=True) as ypls:
        print(ypls.scan_process(ypls.proc.pid))
        print(ypls.scan_file(ypls_exe))
        print(ypls.scan_data(data))


if __name__ == '__main__':
    test()
