import threading
import time


class Thread(threading.Thread):

    """
    This class overrides standard Thread implementation.
    Adds return value of a ran function.
    It is accessible via 'result' variable. It is also returned by call to join()
    If function finished with exception, join raises it in the calling thread
    """

    def __init__(self, daemon=False, **kwargs):
        """ See arguments of threading.Thread """
        threading.Thread.__init__(self, **kwargs)
        self.result = None
        self.exception = None
        self.daemon = daemon

    def run(self):
        try:
            if self._target:
                self.result = self._target(*self._args, **self._kwargs)
        except BaseException as ex:
            self.exception = ex
        finally:
            # Avoid a refcycle if the thread is running a function with
            # an argument that has a member that points to the thread.
            del self._target, self._args, self._kwargs

    def join(self, timeout=None, raise_on_timeout=False):
        super().join(timeout)
        if raise_on_timeout and self.is_alive():
            raise TimeoutError

        if self.exception:
            raise self.exception

        return self.result


class Timeout:

    """ This class can be used to tell, if execution of some part of code is taking more than predefined time """

    def __init__(self, timeout):
        """ Initialize class with timeout (in seconds) """
        self.thread = Thread(daemon=True, target=time.sleep, args=(timeout,))
        self.thread.start()

    def reached(self):
        """ Returns True if timeout was reached """
        return not self.thread.is_alive()

    def wait(self, duration=None):
        """ Waits till timeout is reached or 'duration' seconds """
        self.thread.join(duration)


class StopFlag:

    def __init__(self, initial_state=False):
        self._stop = threading.Event()
        if initial_state:
            self._stop.set()

    def stop(self):
        """ Set the internal event -> bool(self) == True """
        self._stop.set()

    def run(self):
        """ Clear the internal event -> bool(self) == False """
        self._stop.clear()

    def wait(self, timeout=None):
        """ Wait till the event is signaled for at most timeout seconds """
        self._stop.wait(timeout)

    def __bool__(self):
        return self._stop.is_set()

    def __nonzero__(self):
        return self.__bool__()


def example():
    t = Thread(target=" ".join, args=(["Hello", "world!"],))
    t.daemon = True
    t.start()

    result = t.join()
    print(result)


if __name__ == '__main__':
    example()
