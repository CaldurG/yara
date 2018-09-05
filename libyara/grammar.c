/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         yara_yyparse
#define yylex           yara_yylex
#define yyerror         yara_yyerror
#define yylval          yara_yylval
#define yychar          yara_yychar
#define yydebug         yara_yydebug
#define yynerrs         yara_yynerrs

/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 30 "grammar.y"



#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>

#include <yara/integers.h>
#include <yara/utils.h>
#include <yara/strutils.h>
#include <yara/compiler.h>
#include <yara/object.h>
#include <yara/sizedstr.h>
#include <yara/exec.h>
#include <yara/error.h>
#include <yara/mem.h>
#include <yara/lexer.h>
#include <yara/parser.h>

#if defined(_MSC_VER)
#define llabs _abs64
#endif

#define YYERROR_VERBOSE

#define YYMALLOC yr_malloc
#define YYFREE yr_free

#define INTEGER_SET_ENUMERATION   1
#define INTEGER_SET_RANGE         2

#define fail_if_error(e) \
    if (e != ERROR_SUCCESS) \
    { \
      compiler->last_error = e; \
      yyerror(yyscanner, compiler, NULL); \
      YYERROR; \
    } \


#define check_type_with_cleanup(expression, expected_type, op, cleanup) \
    if (((expression.type) & (expected_type)) == 0) \
    { \
      switch(expression.type) \
      { \
        case EXPRESSION_TYPE_INTEGER: \
          yr_compiler_set_error_extra_info( \
              compiler, "wrong type \"integer\" for " op " operator"); \
          break; \
        case EXPRESSION_TYPE_FLOAT: \
          yr_compiler_set_error_extra_info( \
              compiler, "wrong type \"float\" for " op " operator"); \
          break; \
        case EXPRESSION_TYPE_STRING: \
          yr_compiler_set_error_extra_info( \
              compiler, "wrong type \"string\" for " op " operator"); \
          break; \
        case EXPRESSION_TYPE_BOOLEAN: \
          yr_compiler_set_error_extra_info( \
              compiler, "wrong type \"boolean\" for " op " operator"); \
          break; \
      } \
      cleanup; \
      compiler->last_error = ERROR_WRONG_TYPE; \
      yyerror(yyscanner, compiler, NULL); \
      YYERROR; \
    }


#define check_type(expression, expected_type, op) \
    check_type_with_cleanup(expression, expected_type, op, )


/* Line 371 of yacc.c  */
#line 152 "grammar.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.tab.h".  */
#ifndef YY_YARA_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YARA_YY_GRAMMAR_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yara_yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _END_OF_FILE_ = 0,
     _END_OF_INCLUDED_FILE_ = 258,
     _DOT_DOT_ = 259,
     _RULE_ = 260,
     _PRIVATE_ = 261,
     _GLOBAL_ = 262,
     _META_ = 263,
     _STRINGS_ = 264,
     _CONDITION_ = 265,
     _IDENTIFIER_ = 266,
     _STRING_IDENTIFIER_ = 267,
     _STRING_COUNT_ = 268,
     _STRING_OFFSET_ = 269,
     _STRING_LENGTH_ = 270,
     _STRING_IDENTIFIER_WITH_WILDCARD_ = 271,
     _NUMBER_ = 272,
     _DOUBLE_ = 273,
     _INTEGER_FUNCTION_ = 274,
     _TEXT_STRING_ = 275,
     _HEX_STRING_ = 276,
     _REGEXP_ = 277,
     _ASCII_ = 278,
     _WIDE_ = 279,
     _XOR_ = 280,
     _NOCASE_ = 281,
     _FULLWORD_ = 282,
     _LEET_ = 283,
     _AT_ = 284,
     _FILESIZE_ = 285,
     _ENTRYPOINT_ = 286,
     _ALL_ = 287,
     _ANY_ = 288,
     _IN_ = 289,
     _OF_ = 290,
     _FOR_ = 291,
     _THEM_ = 292,
     _MATCHES_ = 293,
     _CONTAINS_ = 294,
     _IMPORT_ = 295,
     _TRUE_ = 296,
     _FALSE_ = 297,
     _OR_ = 298,
     _AND_ = 299,
     _NOT_ = 300,
     _EQ_ = 301,
     _NEQ_ = 302,
     _LT_ = 303,
     _LE_ = 304,
     _GT_ = 305,
     _GE_ = 306,
     _SHIFT_LEFT_ = 307,
     _SHIFT_RIGHT_ = 308,
     UNARY_MINUS = 309
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 237 "grammar.y"

  EXPRESSION      expression;
  SIZED_STRING*   sized_string;
  char*           c_string;
  int64_t         integer;
  double          double_;
  YR_STRING*      string;
  YR_META*        meta;
  YR_RULE*        rule;


/* Line 387 of yacc.c  */
#line 262 "grammar.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yara_yyparse (void *YYPARSE_PARAM);
#else
int yara_yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yara_yyparse (void *yyscanner, YR_COMPILER* compiler);
#else
int yara_yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YARA_YY_GRAMMAR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 289 "grammar.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   376

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNRULES -- Number of states.  */
#define YYNSTATES  213

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    61,    56,     2,
      72,    73,    59,    57,    74,    58,    69,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,     2,
       2,    68,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,    60,    71,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,    54,    66,    62,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    63,
      64
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    14,    18,    22,    25,
      28,    29,    30,    42,    43,    47,    48,    52,    56,    57,
      60,    62,    64,    65,    68,    70,    73,    75,    78,    82,
      86,    91,    95,    99,   101,   104,   105,   111,   112,   118,
     122,   123,   126,   128,   130,   132,   134,   136,   138,   140,
     144,   149,   154,   155,   157,   159,   163,   165,   167,   169,
     171,   175,   179,   181,   185,   189,   193,   194,   195,   207,
     208,   218,   222,   225,   226,   231,   232,   237,   241,   245,
     249,   253,   257,   261,   263,   267,   271,   273,   279,   281,
     285,   286,   291,   293,   295,   299,   301,   303,   305,   307,
     309,   313,   315,   317,   322,   324,   326,   328,   330,   335,
     337,   342,   344,   346,   349,   353,   357,   361,   365,   369,
     373,   377,   381,   384,   388,   392
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      76,     0,    -1,    -1,    76,    78,    -1,    76,    77,    -1,
      76,     1,    78,    -1,    76,     1,    77,    -1,    76,     1,
      64,    -1,    76,     3,    -1,    40,    20,    -1,    -1,    -1,
      84,     5,    11,    79,    86,    65,    81,    82,    80,    83,
      66,    -1,    -1,     8,    67,    88,    -1,    -1,     9,    67,
      90,    -1,    10,    67,   100,    -1,    -1,    84,    85,    -1,
       6,    -1,     7,    -1,    -1,    67,    87,    -1,    11,    -1,
      87,    11,    -1,    89,    -1,    88,    89,    -1,    11,    68,
      20,    -1,    11,    68,    17,    -1,    11,    68,    58,    17,
      -1,    11,    68,    41,    -1,    11,    68,    42,    -1,    91,
      -1,    90,    91,    -1,    -1,    12,    68,    92,    20,    94,
      -1,    -1,    12,    68,    93,    22,    94,    -1,    12,    68,
      21,    -1,    -1,    94,    95,    -1,    24,    -1,    23,    -1,
      26,    -1,    27,    -1,    28,    -1,    25,    -1,    11,    -1,
      96,    69,    11,    -1,    96,    70,   115,    71,    -1,    96,
      72,    97,    73,    -1,    -1,    98,    -1,   101,    -1,    98,
      74,   101,    -1,    22,    -1,   101,    -1,    41,    -1,    42,
      -1,   115,    38,    99,    -1,   115,    39,   115,    -1,    12,
      -1,    12,    29,   115,    -1,    12,    34,   108,    -1,    36,
     114,     1,    -1,    -1,    -1,    36,   114,    11,    34,   102,
     107,    67,   103,    72,   100,    73,    -1,    -1,    36,   114,
      35,   110,    67,   104,    72,   100,    73,    -1,   114,    35,
     110,    -1,    45,   100,    -1,    -1,   100,    44,   105,   100,
      -1,    -1,   100,    43,   106,   100,    -1,   115,    48,   115,
      -1,   115,    50,   115,    -1,   115,    49,   115,    -1,   115,
      51,   115,    -1,   115,    46,   115,    -1,   115,    47,   115,
      -1,   115,    -1,    72,   101,    73,    -1,    72,   109,    73,
      -1,   108,    -1,    72,   115,     4,   115,    73,    -1,   115,
      -1,   109,    74,   115,    -1,    -1,    72,   111,   112,    73,
      -1,    37,    -1,   113,    -1,   112,    74,   113,    -1,    12,
      -1,    16,    -1,   115,    -1,    32,    -1,    33,    -1,    72,
     115,    73,    -1,    30,    -1,    31,    -1,    19,    72,   115,
      73,    -1,    17,    -1,    18,    -1,    20,    -1,    13,    -1,
      14,    70,   115,    71,    -1,    14,    -1,    15,    70,   115,
      71,    -1,    15,    -1,    96,    -1,    58,   115,    -1,   115,
      57,   115,    -1,   115,    58,   115,    -1,   115,    59,   115,
      -1,   115,    60,   115,    -1,   115,    61,   115,    -1,   115,
      55,   115,    -1,   115,    56,   115,    -1,   115,    54,   115,
      -1,    62,   115,    -1,   115,    52,   115,    -1,   115,    53,
     115,    -1,    99,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   251,   251,   253,   254,   255,   256,   257,   258,   266,
     279,   284,   278,   305,   308,   338,   341,   366,   371,   372,
     377,   378,   384,   387,   405,   414,   453,   454,   459,   476,
     490,   504,   518,   536,   537,   543,   542,   558,   557,   573,
     587,   588,   593,   594,   595,   596,   597,   598,   603,   689,
     736,   795,   841,   842,   846,   874,   914,   957,   977,   984,
     991,  1003,  1013,  1027,  1042,  1053,  1064,  1093,  1063,  1207,
    1206,  1284,  1290,  1297,  1296,  1342,  1341,  1385,  1392,  1399,
    1406,  1413,  1420,  1427,  1431,  1439,  1440,  1445,  1469,  1482,
    1500,  1499,  1505,  1517,  1518,  1523,  1530,  1541,  1542,  1546,
    1554,  1558,  1566,  1578,  1592,  1600,  1607,  1632,  1644,  1656,
    1672,  1684,  1700,  1747,  1768,  1803,  1838,  1872,  1897,  1914,
    1924,  1934,  1944,  1954,  1974,  1994
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"end of included file\"",
  "\"..\"", "\"<rule>\"", "\"<private>\"", "\"<global>\"", "\"<meta>\"",
  "\"<strings>\"", "\"<condition>\"", "\"identifier\"",
  "\"string identifier\"", "\"string count\"", "\"string offset\"",
  "\"string length\"", "\"string identifier with wildcard\"",
  "\"integer number\"", "\"floating point number\"",
  "\"integer function\"", "\"text string\"", "\"hex string\"",
  "\"regular expression\"", "\"<ascii>\"", "\"<wide>\"", "\"<xor>\"",
  "\"<nocase>\"", "\"<fullword>\"", "\"<leet>\"", "\"<at>\"",
  "\"<filesize>\"", "\"<entrypoint>\"", "\"<all>\"", "\"<any>\"",
  "\"<in>\"", "\"<of>\"", "\"<for>\"", "\"<them>\"", "\"<matches>\"",
  "\"<contains>\"", "\"<import>\"", "\"<true>\"", "\"<false\"", "\"<or>\"",
  "\"<and>\"", "\"<not>\"", "\"==\"", "\"!=\"", "\"<\"", "\"<=\"", "\">\"",
  "\">=\"", "\"<<\"", "\">>\"", "'|'", "'^'", "'&'", "'+'", "'-'", "'*'",
  "'\\\\'", "'%'", "'~'", "UNARY_MINUS", "\"include\"", "'{'", "'}'",
  "':'", "'='", "'.'", "'['", "']'", "'('", "')'", "','", "$accept",
  "rules", "import", "rule", "@1", "$@2", "meta", "strings", "condition",
  "rule_modifiers", "rule_modifier", "tags", "tag_list",
  "meta_declarations", "meta_declaration", "string_declarations",
  "string_declaration", "$@3", "$@4", "string_modifiers",
  "string_modifier", "identifier", "arguments", "arguments_list", "regexp",
  "boolean_expression", "expression", "$@5", "$@6", "$@7", "$@8", "$@9",
  "integer_set", "range", "integer_enumeration", "string_set", "$@10",
  "string_enumeration", "string_enumeration_item", "for_expression",
  "primary_expression", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   124,    94,    38,    43,    45,    42,
      92,    37,   126,   309,   310,   123,   125,    58,    61,    46,
      91,    93,    40,    41,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    76,    76,    76,    76,    76,    76,    77,
      79,    80,    78,    81,    81,    82,    82,    83,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      89,    89,    89,    90,    90,    92,    91,    93,    91,    91,
      94,    94,    95,    95,    95,    95,    95,    95,    96,    96,
      96,    96,    97,    97,    98,    98,    99,   100,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   103,   101,   104,
     101,   101,   101,   105,   101,   106,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   107,   107,   108,   109,   109,
     111,   110,   110,   112,   112,   113,   113,   114,   114,   114,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     3,     3,     3,     2,     2,
       0,     0,    11,     0,     3,     0,     3,     3,     0,     2,
       1,     1,     0,     2,     1,     2,     1,     2,     3,     3,
       4,     3,     3,     1,     2,     0,     5,     0,     5,     3,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     4,     0,     1,     1,     3,     1,     1,     1,     1,
       3,     3,     1,     3,     3,     3,     0,     0,    11,     0,
       9,     3,     2,     0,     4,     0,     4,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     5,     1,     3,
       0,     4,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     4,     1,     1,     1,     1,     4,     1,
       4,     1,     1,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    18,     8,     0,     4,     3,     0,     7,
       6,     5,     9,     0,    20,    21,    19,    10,    22,     0,
       0,    24,    23,    13,    25,     0,    15,     0,     0,    11,
       0,    14,    26,     0,     0,     0,    27,     0,    16,    33,
       0,     0,    29,    28,    31,    32,     0,    35,    34,     0,
      12,    30,    39,     0,     0,    48,    62,   107,   109,   111,
     104,   105,     0,   106,    56,   101,   102,    98,    99,     0,
      58,    59,     0,     0,     0,     0,   112,   125,    17,    57,
       0,    83,    40,    40,     0,     0,     0,     0,     0,     0,
       0,    97,    72,   113,   122,     0,    57,    83,     0,     0,
      52,    75,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,    38,    63,     0,    64,     0,     0,     0,
       0,    65,     0,     0,    84,   100,    49,     0,     0,    53,
      54,     0,     0,    92,    90,    71,    60,    61,    81,    82,
      77,    79,    78,    80,   123,   124,   121,   119,   120,   114,
     115,   116,   117,   118,    43,    42,    47,    44,    45,    46,
      41,     0,   108,   110,   103,    66,     0,    50,    51,     0,
      76,    74,     0,     0,     0,    69,    55,    95,    96,     0,
      93,     0,     0,     0,    86,     0,    91,     0,    87,     0,
      88,    67,     0,    94,    85,     0,     0,     0,    89,     0,
      70,     0,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     6,     7,    18,    34,    26,    29,    41,     8,
      16,    20,    22,    31,    32,    38,    39,    53,    54,   122,
     170,    76,   138,   139,    77,    95,    79,   184,   206,   195,
     142,   141,   193,   126,   199,   145,   182,   189,   190,    80,
      81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -74
static const yytype_int16 yypact[] =
{
     -74,    98,   -74,   -30,   -74,   -11,   -74,   -74,    23,   -74,
     -74,   -74,   -74,     1,   -74,   -74,   -74,   -74,   -53,     6,
      -7,   -74,    43,    57,   -74,     3,    80,    84,    33,   -74,
      42,    84,   -74,    90,   102,    55,   -74,    46,    90,   -74,
      61,    56,   -74,   -74,   -74,   -74,   116,    14,   -74,    49,
     -74,   -74,   -74,   119,   118,   -74,   -21,   -74,    71,    76,
     -74,   -74,    75,   -74,   -74,   -74,   -74,   -74,   -74,   112,
     -74,   -74,    49,   137,   137,    49,     4,   -74,    34,   -74,
     114,   213,   -74,   -74,   137,    86,   137,   137,   137,   137,
      21,   315,   -74,   -74,   -74,    34,    88,   185,   152,   137,
      49,   -74,   -74,   -13,   142,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   274,   274,   315,   137,   -74,   255,   275,   133,
     223,   -74,   131,   -13,   -74,   -74,   -74,   295,    93,    95,
      40,    49,    49,   -74,   -74,   -74,   -74,   315,   315,   315,
     315,   315,   315,   315,    59,    59,   120,   144,   169,    27,
      27,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   158,   -74,   -74,   -74,   -74,   104,   -74,   -74,    49,
     138,   -74,    -1,   137,   111,   -74,    40,   -74,   -74,    35,
     -74,   233,   137,   140,   -74,   126,   -74,    -1,   -74,    62,
     158,   -74,    49,   -74,   -74,   137,   136,   -40,   315,    49,
     -74,   -18,   -74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   222,   244,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   218,   -74,   212,   -74,   -74,   170,
     -74,   -74,   -74,   -74,   150,   -49,   -73,   -74,   -74,   -74,
     -74,   -74,   -74,    72,   -74,   122,   -74,   -74,    60,   226,
     -68
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -98
static const yytype_int16 yytable[] =
{
      78,    91,    96,   101,   102,    93,    94,    97,    84,    12,
       5,   187,    17,    85,    19,   188,   124,    21,   127,   128,
     129,   130,   131,    92,   143,   101,   102,   140,    13,    14,
      15,   137,   132,   210,     9,    52,   -37,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    24,   212,   133,   171,    23,   144,
      55,    56,    57,    58,    59,    25,    60,    61,    62,    63,
      27,    64,    42,    98,    99,    43,   100,   101,   102,    65,
      66,    67,    68,   -57,   -57,    69,   119,   120,   121,    28,
      70,    71,   180,   181,    72,    30,    44,    45,     2,     3,
      33,     4,    37,   -18,   -18,   -18,   186,    73,   196,   197,
      35,    74,    40,    46,    47,   191,   117,   118,   119,   120,
     121,    75,    50,    55,   200,    57,    58,    59,    49,    60,
      61,    62,    63,    51,    64,   204,   205,   208,     5,    82,
      83,    86,    65,    66,    67,    68,    87,    88,    55,   103,
      57,    58,    59,   207,    60,    61,    62,    63,   125,    64,
     211,   134,   183,   136,    64,   175,   178,    65,    66,   179,
      73,   185,   112,   113,    74,   115,   116,   117,   118,   119,
     120,   121,   102,   192,    89,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    73,   112,   113,   202,    74,
     116,   117,   118,   119,   120,   121,   174,   201,   209,    89,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     -97,   112,   113,   104,   105,    10,   117,   118,   119,   120,
     121,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    11,   -97,    36,
      48,   104,   105,   123,   146,   176,   194,   203,   135,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    90,   135,   164,   165,   166,
     167,   168,   169,     0,     0,     0,   198,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   172,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   173,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-74)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      49,    69,    75,    43,    44,    73,    74,    75,    29,    20,
      40,    12,    11,    34,    67,    16,    84,    11,    86,    87,
      88,    89,     1,    72,    37,    43,    44,   100,     5,     6,
       7,    99,    11,    73,    64,    21,    22,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    11,    73,    35,   125,    65,    72,
      11,    12,    13,    14,    15,     8,    17,    18,    19,    20,
      67,    22,    17,    69,    70,    20,    72,    43,    44,    30,
      31,    32,    33,    43,    44,    36,    59,    60,    61,     9,
      41,    42,   141,   142,    45,    11,    41,    42,     0,     1,
      67,     3,    12,     5,     6,     7,   179,    58,    73,    74,
      68,    62,    10,    58,    68,   183,    57,    58,    59,    60,
      61,    72,    66,    11,   192,    13,    14,    15,    67,    17,
      18,    19,    20,    17,    22,    73,    74,   205,    40,    20,
      22,    70,    30,    31,    32,    33,    70,    72,    11,    35,
      13,    14,    15,   202,    17,    18,    19,    20,    72,    22,
     209,    73,     4,    11,    22,    34,    73,    30,    31,    74,
      58,    67,    52,    53,    62,    55,    56,    57,    58,    59,
      60,    61,    44,    72,    72,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    58,    52,    53,    72,    62,
      56,    57,    58,    59,    60,    61,    73,    67,    72,    72,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      35,    52,    53,    38,    39,     3,    57,    58,    59,    60,
      61,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,     3,    35,    31,
      38,    38,    39,    83,   104,   133,   184,   197,    73,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    69,    73,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    73,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    76,     0,     1,     3,    40,    77,    78,    84,    64,
      77,    78,    20,     5,     6,     7,    85,    11,    79,    67,
      86,    11,    87,    65,    11,     8,    81,    67,     9,    82,
      11,    88,    89,    67,    80,    68,    89,    12,    90,    91,
      10,    83,    17,    20,    41,    42,    58,    68,    91,    67,
      66,    17,    21,    92,    93,    11,    12,    13,    14,    15,
      17,    18,    19,    20,    22,    30,    31,    32,    33,    36,
      41,    42,    45,    58,    62,    72,    96,    99,   100,   101,
     114,   115,    20,    22,    29,    34,    70,    70,    72,    72,
     114,   115,   100,   115,   115,   100,   101,   115,    69,    70,
      72,    43,    44,    35,    38,    39,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    94,    94,   115,    72,   108,   115,   115,   115,
     115,     1,    11,    35,    73,    73,    11,   115,    97,    98,
     101,   106,   105,    37,    72,   110,    99,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,    23,    24,    25,    26,    27,    28,
      95,   115,    71,    71,    73,    34,   110,    71,    73,    74,
     100,   100,   111,     4,   102,    67,   101,    12,    16,   112,
     113,   115,    72,   107,   108,   104,    73,    74,    73,   109,
     115,    67,    72,   113,    73,    74,   103,   100,   115,    72,
      73,   100,    73
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (yyscanner, compiler, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, yyscanner, compiler)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, yyscanner, compiler); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *yyscanner, YR_COMPILER* compiler)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yyscanner, compiler)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    void *yyscanner;
    YR_COMPILER* compiler;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yyscanner);
  YYUSE (compiler);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *yyscanner, YR_COMPILER* compiler)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yyscanner, compiler)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    void *yyscanner;
    YR_COMPILER* compiler;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yyscanner, compiler);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, void *yyscanner, YR_COMPILER* compiler)
#else
static void
yy_reduce_print (yyvsp, yyrule, yyscanner, compiler)
    YYSTYPE *yyvsp;
    int yyrule;
    void *yyscanner;
    YR_COMPILER* compiler;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , yyscanner, compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, yyscanner, compiler); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void *yyscanner, YR_COMPILER* compiler)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yyscanner, compiler)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    void *yyscanner;
    YR_COMPILER* compiler;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yyscanner);
  YYUSE (compiler);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 11: /* "identifier" */
/* Line 1398 of yacc.c  */
#line 224 "grammar.y"
        { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; };
/* Line 1398 of yacc.c  */
#line 1461 "grammar.tab.c"
        break;
      case 12: /* "string identifier" */
/* Line 1398 of yacc.c  */
#line 228 "grammar.y"
        { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; };
/* Line 1398 of yacc.c  */
#line 1468 "grammar.tab.c"
        break;
      case 13: /* "string count" */
/* Line 1398 of yacc.c  */
#line 225 "grammar.y"
        { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; };
/* Line 1398 of yacc.c  */
#line 1475 "grammar.tab.c"
        break;
      case 14: /* "string offset" */
/* Line 1398 of yacc.c  */
#line 226 "grammar.y"
        { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; };
/* Line 1398 of yacc.c  */
#line 1482 "grammar.tab.c"
        break;
      case 15: /* "string length" */
/* Line 1398 of yacc.c  */
#line 227 "grammar.y"
        { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; };
/* Line 1398 of yacc.c  */
#line 1489 "grammar.tab.c"
        break;
      case 16: /* "string identifier with wildcard" */
/* Line 1398 of yacc.c  */
#line 229 "grammar.y"
        { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; };
/* Line 1398 of yacc.c  */
#line 1496 "grammar.tab.c"
        break;
      case 20: /* "text string" */
/* Line 1398 of yacc.c  */
#line 230 "grammar.y"
        { yr_free(((*yyvaluep).sized_string)); ((*yyvaluep).sized_string) = NULL; };
/* Line 1398 of yacc.c  */
#line 1503 "grammar.tab.c"
        break;
      case 21: /* "hex string" */
/* Line 1398 of yacc.c  */
#line 231 "grammar.y"
        { yr_free(((*yyvaluep).sized_string)); ((*yyvaluep).sized_string) = NULL; };
/* Line 1398 of yacc.c  */
#line 1510 "grammar.tab.c"
        break;
      case 22: /* "regular expression" */
/* Line 1398 of yacc.c  */
#line 232 "grammar.y"
        { yr_free(((*yyvaluep).sized_string)); ((*yyvaluep).sized_string) = NULL; };
/* Line 1398 of yacc.c  */
#line 1517 "grammar.tab.c"
        break;
      case 97: /* arguments */
/* Line 1398 of yacc.c  */
#line 234 "grammar.y"
        { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; };
/* Line 1398 of yacc.c  */
#line 1524 "grammar.tab.c"
        break;
      case 98: /* arguments_list */
/* Line 1398 of yacc.c  */
#line 235 "grammar.y"
        { yr_free(((*yyvaluep).c_string)); ((*yyvaluep).c_string) = NULL; };
/* Line 1398 of yacc.c  */
#line 1531 "grammar.tab.c"
        break;

      default:
        break;
    }
}




/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *yyscanner, YR_COMPILER* compiler)
#else
int
yyparse (yyscanner, compiler)
    void *yyscanner;
    YR_COMPILER* compiler;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 8:
/* Line 1792 of yacc.c  */
#line 259 "grammar.y"
    {
        _yr_compiler_pop_file_name(compiler);
      }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 267 "grammar.y"
    {
        int result = yr_parser_reduce_import(yyscanner, (yyvsp[(2) - (2)].sized_string));

        yr_free((yyvsp[(2) - (2)].sized_string));

        fail_if_error(result);
      }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 279 "grammar.y"
    {
        fail_if_error(yr_parser_reduce_rule_declaration_phase_1(
            yyscanner, (int32_t) (yyvsp[(1) - (3)].integer), (yyvsp[(3) - (3)].c_string), &(yyval.rule)));
      }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 284 "grammar.y"
    {
        YR_RULE* rule = (yyvsp[(4) - (8)].rule); // rule created in phase 1

        rule->tags = (yyvsp[(5) - (8)].c_string);
        rule->metas = (yyvsp[(7) - (8)].meta);
        rule->strings = (yyvsp[(8) - (8)].string);
      }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 292 "grammar.y"
    {
        int result = yr_parser_reduce_rule_declaration_phase_2(
            yyscanner, (yyvsp[(4) - (11)].rule)); // rule created in phase 1

        yr_free((yyvsp[(3) - (11)].c_string));

        fail_if_error(result);
      }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 305 "grammar.y"
    {
        (yyval.meta) = NULL;
      }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 309 "grammar.y"
    {
        int result;

        // Each rule have a list of meta-data info, consisting in a
        // sequence of YR_META structures. The last YR_META structure does
        // not represent a real meta-data, it's just a end-of-list marker
        // identified by a specific type (META_TYPE_NULL). Here we
        // write the end-of-list marker.

        YR_META null_meta;

        memset(&null_meta, 0xFF, sizeof(YR_META));
        null_meta.type = META_TYPE_NULL;

        result = yr_arena_write_data(
            compiler->metas_arena,
            &null_meta,
            sizeof(YR_META),
            NULL);

        (yyval.meta) = (yyvsp[(3) - (3)].meta);

        fail_if_error(result);
      }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 338 "grammar.y"
    {
        (yyval.string) = NULL;
      }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 342 "grammar.y"
    {
        // Each rule have a list of strings, consisting in a sequence
        // of YR_STRING structures. The last YR_STRING structure does not
        // represent a real string, it's just a end-of-list marker
        // identified by a specific flag (STRING_FLAGS_NULL). Here we
        // write the end-of-list marker.

        YR_STRING null_string;

        memset(&null_string, 0xFF, sizeof(YR_STRING));
        null_string.g_flags = STRING_GFLAGS_NULL;

        fail_if_error(yr_arena_write_data(
            compiler->strings_arena,
            &null_string,
            sizeof(YR_STRING),
            NULL));

        (yyval.string) = (yyvsp[(3) - (3)].string);
      }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 371 "grammar.y"
    { (yyval.integer) = 0;  }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 372 "grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (2)].integer) | (yyvsp[(2) - (2)].integer); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 377 "grammar.y"
    { (yyval.integer) = RULE_GFLAGS_PRIVATE; }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 378 "grammar.y"
    { (yyval.integer) = RULE_GFLAGS_GLOBAL; }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 384 "grammar.y"
    {
        (yyval.c_string) = NULL;
      }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 388 "grammar.y"
    {
        // Tags list is represented in the arena as a sequence
        // of null-terminated strings, the sequence ends with an
        // additional null character. Here we write the ending null
        //character. Example: tag1\0tag2\0tag3\0\0

        int result = yr_arena_write_string(
            yyget_extra(yyscanner)->sz_arena, "", NULL);

        fail_if_error(result);

        (yyval.c_string) = (yyvsp[(2) - (2)].c_string);
      }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 406 "grammar.y"
    {
        int result = yr_arena_write_string(
            yyget_extra(yyscanner)->sz_arena, (yyvsp[(1) - (1)].c_string), &(yyval.c_string));

        yr_free((yyvsp[(1) - (1)].c_string));

        fail_if_error(result);
      }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 415 "grammar.y"
    {
        int result = ERROR_SUCCESS;

        char* tag_name = (yyvsp[(1) - (2)].c_string);
        size_t tag_length = tag_name != NULL ? strlen(tag_name) : 0;

        while (tag_length > 0)
        {
          if (strcmp(tag_name, (yyvsp[(2) - (2)].c_string)) == 0)
          {
            yr_compiler_set_error_extra_info(compiler, tag_name);
            result = ERROR_DUPLICATED_TAG_IDENTIFIER;
            break;
          }

          tag_name = (char*) yr_arena_next_address(
              yyget_extra(yyscanner)->sz_arena,
              tag_name,
              tag_length + 1);

          tag_length = tag_name != NULL ? strlen(tag_name) : 0;
        }

        if (result == ERROR_SUCCESS)
          result = yr_arena_write_string(
              yyget_extra(yyscanner)->sz_arena, (yyvsp[(2) - (2)].c_string), NULL);

        yr_free((yyvsp[(2) - (2)].c_string));

        fail_if_error(result);

        (yyval.c_string) = (yyvsp[(1) - (2)].c_string);
      }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 453 "grammar.y"
    {  (yyval.meta) = (yyvsp[(1) - (1)].meta); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 454 "grammar.y"
    {  (yyval.meta) = (yyvsp[(1) - (2)].meta); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 460 "grammar.y"
    {
        SIZED_STRING* sized_string = (yyvsp[(3) - (3)].sized_string);

        int result = yr_parser_reduce_meta_declaration(
            yyscanner,
            META_TYPE_STRING,
            (yyvsp[(1) - (3)].c_string),
            sized_string->c_string,
            0,
            &(yyval.meta));

        yr_free((yyvsp[(1) - (3)].c_string));
        yr_free((yyvsp[(3) - (3)].sized_string));

        fail_if_error(result);
      }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 477 "grammar.y"
    {
        int result = yr_parser_reduce_meta_declaration(
            yyscanner,
            META_TYPE_INTEGER,
            (yyvsp[(1) - (3)].c_string),
            NULL,
            (yyvsp[(3) - (3)].integer),
            &(yyval.meta));

        yr_free((yyvsp[(1) - (3)].c_string));

        fail_if_error(result);
      }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 491 "grammar.y"
    {
        int result = yr_parser_reduce_meta_declaration(
            yyscanner,
            META_TYPE_INTEGER,
            (yyvsp[(1) - (4)].c_string),
            NULL,
            -(yyvsp[(4) - (4)].integer),
            &(yyval.meta));

        yr_free((yyvsp[(1) - (4)].c_string));

        fail_if_error(result);
      }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 505 "grammar.y"
    {
        int result = yr_parser_reduce_meta_declaration(
            yyscanner,
            META_TYPE_BOOLEAN,
            (yyvsp[(1) - (3)].c_string),
            NULL,
            true,
            &(yyval.meta));

        yr_free((yyvsp[(1) - (3)].c_string));

        fail_if_error(result);
      }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 519 "grammar.y"
    {
        int result = yr_parser_reduce_meta_declaration(
            yyscanner,
            META_TYPE_BOOLEAN,
            (yyvsp[(1) - (3)].c_string),
            NULL,
            false,
            &(yyval.meta));

        yr_free((yyvsp[(1) - (3)].c_string));

        fail_if_error(result);
      }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 536 "grammar.y"
    { (yyval.string) = (yyvsp[(1) - (1)].string); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 537 "grammar.y"
    { (yyval.string) = (yyvsp[(1) - (2)].string); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 543 "grammar.y"
    {
        compiler->current_line = yyget_lineno(yyscanner);
      }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 547 "grammar.y"
    {
        int result = yr_parser_reduce_string_declaration(
            yyscanner, (int32_t) (yyvsp[(5) - (5)].integer), (yyvsp[(1) - (5)].c_string), (yyvsp[(4) - (5)].sized_string), &(yyval.string));

        yr_free((yyvsp[(1) - (5)].c_string));
        yr_free((yyvsp[(4) - (5)].sized_string));

        fail_if_error(result);
        compiler->current_line = 0;
      }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 558 "grammar.y"
    {
        compiler->current_line = yyget_lineno(yyscanner);
      }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 562 "grammar.y"
    {
        int result = yr_parser_reduce_string_declaration(
            yyscanner, (int32_t) (yyvsp[(5) - (5)].integer) | STRING_GFLAGS_REGEXP, (yyvsp[(1) - (5)].c_string), (yyvsp[(4) - (5)].sized_string), &(yyval.string));

        yr_free((yyvsp[(1) - (5)].c_string));
        yr_free((yyvsp[(4) - (5)].sized_string));

        fail_if_error(result);

        compiler->current_line = 0;
      }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 574 "grammar.y"
    {
        int result = yr_parser_reduce_string_declaration(
            yyscanner, STRING_GFLAGS_HEXADECIMAL, (yyvsp[(1) - (3)].c_string), (yyvsp[(3) - (3)].sized_string), &(yyval.string));

        yr_free((yyvsp[(1) - (3)].c_string));
        yr_free((yyvsp[(3) - (3)].sized_string));

        fail_if_error(result);
      }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 587 "grammar.y"
    { (yyval.integer) = 0; }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 588 "grammar.y"
    { (yyval.integer) = (yyvsp[(1) - (2)].integer) | (yyvsp[(2) - (2)].integer); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 593 "grammar.y"
    { (yyval.integer) = STRING_GFLAGS_WIDE; }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 594 "grammar.y"
    { (yyval.integer) = STRING_GFLAGS_ASCII; }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 595 "grammar.y"
    { (yyval.integer) = STRING_GFLAGS_NO_CASE; }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 596 "grammar.y"
    { (yyval.integer) = STRING_GFLAGS_FULL_WORD; }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 597 "grammar.y"
    { (yyval.integer) = STRING_GFLAGS_LEET; }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 598 "grammar.y"
    { (yyval.integer) = STRING_GFLAGS_XOR; }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 604 "grammar.y"
    {
        int result = ERROR_SUCCESS;
        int var_index = yr_parser_lookup_loop_variable(yyscanner, (yyvsp[(1) - (1)].c_string));

        if (var_index >= 0)
        {
          result = yr_parser_emit_with_arg(
              yyscanner,
              OP_PUSH_M,
              LOOP_LOCAL_VARS * var_index,
              NULL,
              NULL);

          (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
          (yyval.expression).value.integer = UNDEFINED;
          (yyval.expression).identifier = compiler->loop_identifier[var_index];
        }
        else
        {
          // Search for identifier within the global namespace, where the
          // externals variables reside.

          YR_OBJECT* object = (YR_OBJECT*) yr_hash_table_lookup(
              compiler->objects_table, (yyvsp[(1) - (1)].c_string), NULL);

          if (object == NULL)
          {
            // If not found, search within the current namespace.
            char* ns = compiler->current_namespace->name;

            object = (YR_OBJECT*) yr_hash_table_lookup(
                compiler->objects_table, (yyvsp[(1) - (1)].c_string), ns);
          }

          if (object != NULL)
          {
            char* id;

            result = yr_arena_write_string(
                compiler->sz_arena, (yyvsp[(1) - (1)].c_string), &id);

            if (result == ERROR_SUCCESS)
              result = yr_parser_emit_with_arg_reloc(
                  yyscanner,
                  OP_OBJ_LOAD,
                  id,
                  NULL,
                  NULL);

            (yyval.expression).type = EXPRESSION_TYPE_OBJECT;
            (yyval.expression).value.object = object;
            (yyval.expression).identifier = object->identifier;
          }
          else
          {
            YR_RULE* rule = (YR_RULE*) yr_hash_table_lookup(
                compiler->rules_table,
                (yyvsp[(1) - (1)].c_string),
                compiler->current_namespace->name);

            if (rule != NULL)
            {
              result = yr_parser_emit_with_arg_reloc(
                  yyscanner,
                  OP_PUSH_RULE,
                  rule,
                  NULL,
                  NULL);

              (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
              (yyval.expression).value.integer = UNDEFINED;
              (yyval.expression).identifier = rule->identifier;
            }
            else
            {
              yr_compiler_set_error_extra_info(compiler, (yyvsp[(1) - (1)].c_string));
              result = ERROR_UNDEFINED_IDENTIFIER;
            }
          }
        }

        yr_free((yyvsp[(1) - (1)].c_string));

        fail_if_error(result);
      }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 690 "grammar.y"
    {
        int result = ERROR_SUCCESS;
        YR_OBJECT* field = NULL;

        if ((yyvsp[(1) - (3)].expression).type == EXPRESSION_TYPE_OBJECT &&
            (yyvsp[(1) - (3)].expression).value.object->type == OBJECT_TYPE_STRUCTURE)
        {
          field = yr_object_lookup_field((yyvsp[(1) - (3)].expression).value.object, (yyvsp[(3) - (3)].c_string));

          if (field != NULL)
          {
            char* ident;

            result = yr_arena_write_string(
                compiler->sz_arena, (yyvsp[(3) - (3)].c_string), &ident);

            if (result == ERROR_SUCCESS)
              result = yr_parser_emit_with_arg_reloc(
                  yyscanner,
                  OP_OBJ_FIELD,
                  ident,
                  NULL,
                  NULL);

            (yyval.expression).type = EXPRESSION_TYPE_OBJECT;
            (yyval.expression).value.object = field;
            (yyval.expression).identifier = field->identifier;
          }
          else
          {
            yr_compiler_set_error_extra_info(compiler, (yyvsp[(3) - (3)].c_string));
            result = ERROR_INVALID_FIELD_NAME;
          }
        }
        else
        {
          yr_compiler_set_error_extra_info(
              compiler, (yyvsp[(1) - (3)].expression).identifier);

          result = ERROR_NOT_A_STRUCTURE;
        }

        yr_free((yyvsp[(3) - (3)].c_string));

        fail_if_error(result);
      }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 737 "grammar.y"
    {
        int result = ERROR_SUCCESS;
        YR_OBJECT_ARRAY* array;
        YR_OBJECT_DICTIONARY* dict;

        if ((yyvsp[(1) - (4)].expression).type == EXPRESSION_TYPE_OBJECT &&
            (yyvsp[(1) - (4)].expression).value.object->type == OBJECT_TYPE_ARRAY)
        {
          if ((yyvsp[(3) - (4)].expression).type != EXPRESSION_TYPE_INTEGER)
          {
            yr_compiler_set_error_extra_info(
                compiler, "array indexes must be of integer type");
            result = ERROR_WRONG_TYPE;
          }

          fail_if_error(result);

          result = yr_parser_emit(
              yyscanner, OP_INDEX_ARRAY, NULL);

          array = object_as_array((yyvsp[(1) - (4)].expression).value.object);

          (yyval.expression).type = EXPRESSION_TYPE_OBJECT;
          (yyval.expression).value.object = array->prototype_item;
          (yyval.expression).identifier = array->identifier;
        }
        else if ((yyvsp[(1) - (4)].expression).type == EXPRESSION_TYPE_OBJECT &&
                 (yyvsp[(1) - (4)].expression).value.object->type == OBJECT_TYPE_DICTIONARY)
        {
          if ((yyvsp[(3) - (4)].expression).type != EXPRESSION_TYPE_STRING)
          {
            yr_compiler_set_error_extra_info(
                compiler, "dictionary keys must be of string type");
            result = ERROR_WRONG_TYPE;
          }

          fail_if_error(result);

          result = yr_parser_emit(
              yyscanner, OP_LOOKUP_DICT, NULL);

          dict = object_as_dictionary((yyvsp[(1) - (4)].expression).value.object);

          (yyval.expression).type = EXPRESSION_TYPE_OBJECT;
          (yyval.expression).value.object = dict->prototype_item;
          (yyval.expression).identifier = dict->identifier;
        }
        else
        {
          yr_compiler_set_error_extra_info(
              compiler, (yyvsp[(1) - (4)].expression).identifier);

          result = ERROR_NOT_INDEXABLE;
        }

        fail_if_error(result);
      }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 796 "grammar.y"
    {
        int result = ERROR_SUCCESS;
        YR_OBJECT_FUNCTION* function;
        char* args_fmt;

        if ((yyvsp[(1) - (4)].expression).type == EXPRESSION_TYPE_OBJECT &&
            (yyvsp[(1) - (4)].expression).value.object->type == OBJECT_TYPE_FUNCTION)
        {
          result = yr_parser_check_types(
              compiler, object_as_function((yyvsp[(1) - (4)].expression).value.object), (yyvsp[(3) - (4)].c_string));

          if (result == ERROR_SUCCESS)
            result = yr_arena_write_string(
                compiler->sz_arena, (yyvsp[(3) - (4)].c_string), &args_fmt);

          if (result == ERROR_SUCCESS)
            result = yr_parser_emit_with_arg_reloc(
                yyscanner,
                OP_CALL,
                args_fmt,
                NULL,
                NULL);

          function = object_as_function((yyvsp[(1) - (4)].expression).value.object);

          (yyval.expression).type = EXPRESSION_TYPE_OBJECT;
          (yyval.expression).value.object = function->return_obj;
          (yyval.expression).identifier = function->identifier;
        }
        else
        {
          yr_compiler_set_error_extra_info(
              compiler, (yyvsp[(1) - (4)].expression).identifier);

          result = ERROR_NOT_A_FUNCTION;
        }

        yr_free((yyvsp[(3) - (4)].c_string));

        fail_if_error(result);
      }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 841 "grammar.y"
    { (yyval.c_string) = yr_strdup(""); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 842 "grammar.y"
    { (yyval.c_string) = (yyvsp[(1) - (1)].c_string); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 847 "grammar.y"
    {
        (yyval.c_string) = (char*) yr_malloc(YR_MAX_FUNCTION_ARGS + 1);

        if ((yyval.c_string) == NULL)
          fail_if_error(ERROR_INSUFFICIENT_MEMORY);

        switch((yyvsp[(1) - (1)].expression).type)
        {
          case EXPRESSION_TYPE_INTEGER:
            strlcpy((yyval.c_string), "i", YR_MAX_FUNCTION_ARGS);
            break;
          case EXPRESSION_TYPE_FLOAT:
            strlcpy((yyval.c_string), "f", YR_MAX_FUNCTION_ARGS);
            break;
          case EXPRESSION_TYPE_BOOLEAN:
            strlcpy((yyval.c_string), "b", YR_MAX_FUNCTION_ARGS);
            break;
          case EXPRESSION_TYPE_STRING:
            strlcpy((yyval.c_string), "s", YR_MAX_FUNCTION_ARGS);
            break;
          case EXPRESSION_TYPE_REGEXP:
            strlcpy((yyval.c_string), "r", YR_MAX_FUNCTION_ARGS);
            break;
          default:
            assert(false);
        }
      }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 875 "grammar.y"
    {
        int result = ERROR_SUCCESS;

        if (strlen((yyvsp[(1) - (3)].c_string)) == YR_MAX_FUNCTION_ARGS)
        {
          result = ERROR_TOO_MANY_ARGUMENTS;
        }
        else
        {
          switch((yyvsp[(3) - (3)].expression).type)
          {
            case EXPRESSION_TYPE_INTEGER:
              strlcat((yyvsp[(1) - (3)].c_string), "i", YR_MAX_FUNCTION_ARGS);
              break;
            case EXPRESSION_TYPE_FLOAT:
              strlcat((yyvsp[(1) - (3)].c_string), "f", YR_MAX_FUNCTION_ARGS);
              break;
            case EXPRESSION_TYPE_BOOLEAN:
              strlcat((yyvsp[(1) - (3)].c_string), "b", YR_MAX_FUNCTION_ARGS);
              break;
            case EXPRESSION_TYPE_STRING:
              strlcat((yyvsp[(1) - (3)].c_string), "s", YR_MAX_FUNCTION_ARGS);
              break;
            case EXPRESSION_TYPE_REGEXP:
              strlcat((yyvsp[(1) - (3)].c_string), "r", YR_MAX_FUNCTION_ARGS);
              break;
            default:
              assert(false);
          }
        }

        fail_if_error(result);

        (yyval.c_string) = (yyvsp[(1) - (3)].c_string);
      }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 915 "grammar.y"
    {
        SIZED_STRING* sized_string = (yyvsp[(1) - (1)].sized_string);
        RE* re;
        RE_ERROR error;

        int result = ERROR_SUCCESS;
        int re_flags = 0;

        if (sized_string->flags & SIZED_STRING_FLAGS_NO_CASE)
          re_flags |= RE_FLAGS_NO_CASE;

        if (sized_string->flags & SIZED_STRING_FLAGS_DOT_ALL)
          re_flags |= RE_FLAGS_DOT_ALL;

        result = yr_re_compile(
            sized_string->c_string,
            re_flags,
            compiler->re_code_arena,
            &re,
            &error);

        yr_free((yyvsp[(1) - (1)].sized_string));

        if (result == ERROR_INVALID_REGULAR_EXPRESSION)
          yr_compiler_set_error_extra_info(compiler, error.message);

        if (result == ERROR_SUCCESS)
          result = yr_parser_emit_with_arg_reloc(
              yyscanner,
              OP_PUSH,
              re,
              NULL,
              NULL);

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_REGEXP;
      }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 958 "grammar.y"
    {
        if ((yyvsp[(1) - (1)].expression).type == EXPRESSION_TYPE_STRING)
        {
          if ((yyvsp[(1) - (1)].expression).value.sized_string != NULL)
          {
            yywarning(yyscanner,
              "Using literal string \"%s\" in a boolean operation.",
              (yyvsp[(1) - (1)].expression).value.sized_string->c_string);
          }

          fail_if_error(yr_parser_emit(
              yyscanner, OP_STR_TO_BOOL, NULL));
        }

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 978 "grammar.y"
    {
        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_PUSH, 1, NULL, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 985 "grammar.y"
    {
        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_PUSH, 0, NULL, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 992 "grammar.y"
    {
        check_type((yyvsp[(1) - (3)].expression), EXPRESSION_TYPE_STRING, "matches");
        check_type((yyvsp[(3) - (3)].expression), EXPRESSION_TYPE_REGEXP, "matches");

        fail_if_error(yr_parser_emit(
            yyscanner,
            OP_MATCHES,
            NULL));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 1004 "grammar.y"
    {
        check_type((yyvsp[(1) - (3)].expression), EXPRESSION_TYPE_STRING, "contains");
        check_type((yyvsp[(3) - (3)].expression), EXPRESSION_TYPE_STRING, "contains");

        fail_if_error(yr_parser_emit(
            yyscanner, OP_CONTAINS, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 1014 "grammar.y"
    {
        int result = yr_parser_reduce_string_identifier(
            yyscanner,
            (yyvsp[(1) - (1)].c_string),
            OP_FOUND,
            UNDEFINED);

        yr_free((yyvsp[(1) - (1)].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 1028 "grammar.y"
    {
        int result;

        check_type_with_cleanup((yyvsp[(3) - (3)].expression), EXPRESSION_TYPE_INTEGER, "at", yr_free((yyvsp[(1) - (3)].c_string)));

        result = yr_parser_reduce_string_identifier(
            yyscanner, (yyvsp[(1) - (3)].c_string), OP_FOUND_AT, (yyvsp[(3) - (3)].expression).value.integer);

        yr_free((yyvsp[(1) - (3)].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 1043 "grammar.y"
    {
        int result = yr_parser_reduce_string_identifier(
            yyscanner, (yyvsp[(1) - (3)].c_string), OP_FOUND_IN, UNDEFINED);

        yr_free((yyvsp[(1) - (3)].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 1054 "grammar.y"
    {
        if (compiler->loop_depth > 0)
        {
          compiler->loop_depth--;
          compiler->loop_identifier[compiler->loop_depth] = NULL;
        }

        YYERROR;
      }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 1064 "grammar.y"
    {
        int result = ERROR_SUCCESS;
        int var_index;

        if (compiler->loop_depth == YR_MAX_LOOP_NESTING)
          result = ERROR_LOOP_NESTING_LIMIT_EXCEEDED;

        fail_if_error(result);

        var_index = yr_parser_lookup_loop_variable(
            yyscanner, (yyvsp[(3) - (4)].c_string));

        if (var_index >= 0)
        {
          yr_compiler_set_error_extra_info(
              compiler, (yyvsp[(3) - (4)].c_string));

          result = ERROR_DUPLICATED_LOOP_IDENTIFIER;
        }

        fail_if_error(result);

        // Push end-of-list marker
        result = yr_parser_emit_with_arg(
            yyscanner, OP_PUSH, UNDEFINED, NULL, NULL);

        fail_if_error(result);
      }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 1093 "grammar.y"
    {
        int mem_offset = LOOP_LOCAL_VARS * compiler->loop_depth;
        uint8_t* addr;

        // Clear counter for number of expressions evaluating
        // to true.
        yr_parser_emit_with_arg(
            yyscanner, OP_CLEAR_M, mem_offset + 1, NULL, NULL);

        // Clear iterations counter
        yr_parser_emit_with_arg(
            yyscanner, OP_CLEAR_M, mem_offset + 2, NULL, NULL);

        if ((yyvsp[(6) - (7)].integer) == INTEGER_SET_ENUMERATION)
        {
          // Pop the first integer
          yr_parser_emit_with_arg(
              yyscanner, OP_POP_M, mem_offset, &addr, NULL);
        }
        else // INTEGER_SET_RANGE
        {
          // Pop higher bound of set range
          yr_parser_emit_with_arg(
              yyscanner, OP_POP_M, mem_offset + 3, &addr, NULL);

          // Pop lower bound of set range
          yr_parser_emit_with_arg(
              yyscanner, OP_POP_M, mem_offset, NULL, NULL);
        }

        compiler->loop_address[compiler->loop_depth] = addr;
        compiler->loop_identifier[compiler->loop_depth] = (yyvsp[(3) - (7)].c_string);
        compiler->loop_depth++;
      }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 1128 "grammar.y"
    {
        int mem_offset;

        compiler->loop_depth--;
        mem_offset = LOOP_LOCAL_VARS * compiler->loop_depth;

        // The value at the top of the stack is the result of
        // evaluating the boolean expression, so it could be
        // 0, 1 or UNDEFINED. Add this value to a counter
        // keeping the number of expressions evaluating to true.
        // If the value is UNDEFINED instruction OP_ADD_M
        // does nothing.

        yr_parser_emit_with_arg(
            yyscanner, OP_ADD_M, mem_offset + 1, NULL, NULL);

        // Increment iterations counter
        yr_parser_emit_with_arg(
            yyscanner, OP_INCR_M, mem_offset + 2, NULL, NULL);

        if ((yyvsp[(6) - (11)].integer) == INTEGER_SET_ENUMERATION)
        {
          yr_parser_emit_with_arg_reloc(
              yyscanner,
              OP_JNUNDEF,
              compiler->loop_address[compiler->loop_depth],
              NULL,
              NULL);
        }
        else // INTEGER_SET_RANGE
        {
          // Increment lower bound of integer set
          yr_parser_emit_with_arg(
              yyscanner, OP_INCR_M, mem_offset, NULL, NULL);

          // Push lower bound of integer set
          yr_parser_emit_with_arg(
              yyscanner, OP_PUSH_M, mem_offset, NULL, NULL);

          // Push higher bound of integer set
          yr_parser_emit_with_arg(
              yyscanner, OP_PUSH_M, mem_offset + 3, NULL, NULL);

          // Compare higher bound with lower bound, do loop again
          // if lower bound is still lower or equal than higher bound
          yr_parser_emit_with_arg_reloc(
              yyscanner,
              OP_JLE,
              compiler->loop_address[compiler->loop_depth],
              NULL,
              NULL);

          yr_parser_emit(yyscanner, OP_POP, NULL);
          yr_parser_emit(yyscanner, OP_POP, NULL);
        }

        // Pop end-of-list marker.
        yr_parser_emit(yyscanner, OP_POP, NULL);

        // At this point the loop quantifier (any, all, 1, 2,..)
        // is at the top of the stack. Check if the quantifier
        // is undefined (meaning "all") and replace it with the
        // iterations counter in that case.
        yr_parser_emit_with_arg(
            yyscanner, OP_SWAPUNDEF, mem_offset + 2, NULL, NULL);

        // Compare the loop quantifier with the number of
        // expressions evaluating to true.
        yr_parser_emit_with_arg(
            yyscanner, OP_PUSH_M, mem_offset + 1, NULL, NULL);

        yr_parser_emit(yyscanner, OP_INT_LE, NULL);

        compiler->loop_identifier[compiler->loop_depth] = NULL;
        yr_free((yyvsp[(3) - (11)].c_string));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 1207 "grammar.y"
    {
        int result = ERROR_SUCCESS;
        int mem_offset = LOOP_LOCAL_VARS * compiler->loop_depth;
        uint8_t* addr;

        if (compiler->loop_depth == YR_MAX_LOOP_NESTING)
          result = ERROR_LOOP_NESTING_LIMIT_EXCEEDED;

        if (compiler->loop_for_of_mem_offset != -1)
          result = ERROR_NESTED_FOR_OF_LOOP;

        fail_if_error(result);

        yr_parser_emit_with_arg(
            yyscanner, OP_CLEAR_M, mem_offset + 1, NULL, NULL);

        yr_parser_emit_with_arg(
            yyscanner, OP_CLEAR_M, mem_offset + 2, NULL, NULL);

        // Pop the first string.
        yr_parser_emit_with_arg(
            yyscanner, OP_POP_M, mem_offset, &addr, NULL);

        compiler->loop_for_of_mem_offset = mem_offset;
        compiler->loop_address[compiler->loop_depth] = addr;
        compiler->loop_identifier[compiler->loop_depth] = NULL;
        compiler->loop_depth++;
      }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 1236 "grammar.y"
    {
        int mem_offset;

        compiler->loop_depth--;
        compiler->loop_for_of_mem_offset = -1;

        mem_offset = LOOP_LOCAL_VARS * compiler->loop_depth;

        // Increment counter by the value returned by the
        // boolean expression (0 or 1). If the boolean expression
        // returned UNDEFINED the OP_ADD_M won't do anything.

        yr_parser_emit_with_arg(
            yyscanner, OP_ADD_M, mem_offset + 1, NULL, NULL);

        // Increment iterations counter.
        yr_parser_emit_with_arg(
            yyscanner, OP_INCR_M, mem_offset + 2, NULL, NULL);

        // If next string is not undefined, go back to the
        // beginning of the loop.
        yr_parser_emit_with_arg_reloc(
            yyscanner,
            OP_JNUNDEF,
            compiler->loop_address[compiler->loop_depth],
            NULL,
            NULL);

        // Pop end-of-list marker.
        yr_parser_emit(yyscanner, OP_POP, NULL);

        // At this point the loop quantifier (any, all, 1, 2,..)
        // is at top of the stack. Check if the quantifier is
        // undefined (meaning "all") and replace it with the
        // iterations counter in that case.
        yr_parser_emit_with_arg(
            yyscanner, OP_SWAPUNDEF, mem_offset + 2, NULL, NULL);

        // Compare the loop quantifier with the number of
        // expressions evaluating to true.
        yr_parser_emit_with_arg(
            yyscanner, OP_PUSH_M, mem_offset + 1, NULL, NULL);

        yr_parser_emit(yyscanner, OP_INT_LE, NULL);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;

      }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 1285 "grammar.y"
    {
        yr_parser_emit(yyscanner, OP_OF, NULL);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 1291 "grammar.y"
    {
        yr_parser_emit(yyscanner, OP_NOT, NULL);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 1297 "grammar.y"
    {
        YR_FIXUP* fixup;
        void* jmp_destination_addr;

        fail_if_error(yr_parser_emit_with_arg_reloc(
            yyscanner,
            OP_JFALSE,
            0,          // still don't know the jump destination
            NULL,
            &jmp_destination_addr));

        // create a fixup entry for the jump and push it in the stack
        fixup = (YR_FIXUP*) yr_malloc(sizeof(YR_FIXUP));

        if (fixup == NULL)
          fail_if_error(ERROR_INSUFFICIENT_MEMORY);

        fixup->address = jmp_destination_addr;
        fixup->next = compiler->fixup_stack_head;
        compiler->fixup_stack_head = fixup;
      }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 1319 "grammar.y"
    {
        YR_FIXUP* fixup;
        uint8_t* nop_addr;

        fail_if_error(yr_parser_emit(yyscanner, OP_AND, NULL));

        // Generate a do-nothing instruction (NOP) in order to get its address
        // and use it as the destination for the OP_JFALSE. We can not simply
        // use the address of the OP_AND instruction +1 because we can't be
        // sure that the instruction following the OP_AND is going to be in
        // the same arena page. As we don't have a reliable way of getting the
        // address of the next instruction we generate the OP_NOP.

        fail_if_error(yr_parser_emit(yyscanner, OP_NOP, &nop_addr));

        fixup = compiler->fixup_stack_head;
        *(void**)(fixup->address) = (void*) nop_addr;
        compiler->fixup_stack_head = fixup->next;
        yr_free(fixup);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 1342 "grammar.y"
    {
        YR_FIXUP* fixup;
        void* jmp_destination_addr;

        fail_if_error(yr_parser_emit_with_arg_reloc(
            yyscanner,
            OP_JTRUE,
            0,         // still don't know the jump destination
            NULL,
            &jmp_destination_addr));

        fixup = (YR_FIXUP*) yr_malloc(sizeof(YR_FIXUP));

        if (fixup == NULL)
          fail_if_error(ERROR_INSUFFICIENT_MEMORY);

        fixup->address = jmp_destination_addr;
        fixup->next = compiler->fixup_stack_head;
        compiler->fixup_stack_head = fixup;
      }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 1363 "grammar.y"
    {
        YR_FIXUP* fixup;
        uint8_t* nop_addr;

        fail_if_error(yr_parser_emit(yyscanner, OP_OR, NULL));

        // Generate a do-nothing instruction (NOP) in order to get its address
        // and use it as the destination for the OP_JFALSE. We can not simply
        // use the address of the OP_OR instruction +1 because we can't be
        // sure that the instruction following the OP_AND is going to be in
        // the same arena page. As we don't have a reliable way of getting the
        // address of the next instruction we generate the OP_NOP.

        fail_if_error(yr_parser_emit(yyscanner, OP_NOP, &nop_addr));

        fixup = compiler->fixup_stack_head;
        *(void**)(fixup->address) = (void*)(nop_addr);
        compiler->fixup_stack_head = fixup->next;
        yr_free(fixup);

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 1386 "grammar.y"
    {
        fail_if_error(yr_parser_reduce_operation(
            yyscanner, "<", (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 1393 "grammar.y"
    {
        fail_if_error(yr_parser_reduce_operation(
            yyscanner, ">", (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 1400 "grammar.y"
    {
        fail_if_error(yr_parser_reduce_operation(
            yyscanner, "<=", (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 1407 "grammar.y"
    {
        fail_if_error(yr_parser_reduce_operation(
            yyscanner, ">=", (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 1414 "grammar.y"
    {
        fail_if_error(yr_parser_reduce_operation(
            yyscanner, "==", (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 1421 "grammar.y"
    {
        fail_if_error(yr_parser_reduce_operation(
            yyscanner, "!=", (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)));

        (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
      }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 1428 "grammar.y"
    {
        (yyval.expression) = (yyvsp[(1) - (1)].expression);
      }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 1432 "grammar.y"
    {
        (yyval.expression) = (yyvsp[(2) - (3)].expression);
      }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 1439 "grammar.y"
    { (yyval.integer) = INTEGER_SET_ENUMERATION; }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 1440 "grammar.y"
    { (yyval.integer) = INTEGER_SET_RANGE; }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 1446 "grammar.y"
    {
        int result = ERROR_SUCCESS;

        if ((yyvsp[(2) - (5)].expression).type != EXPRESSION_TYPE_INTEGER)
        {
          yr_compiler_set_error_extra_info(
              compiler, "wrong type for range's lower bound");
          result = ERROR_WRONG_TYPE;
        }

        if ((yyvsp[(4) - (5)].expression).type != EXPRESSION_TYPE_INTEGER)
        {
          yr_compiler_set_error_extra_info(
              compiler, "wrong type for range's upper bound");
          result = ERROR_WRONG_TYPE;
        }

        fail_if_error(result);
      }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 1470 "grammar.y"
    {
        int result = ERROR_SUCCESS;

        if ((yyvsp[(1) - (1)].expression).type != EXPRESSION_TYPE_INTEGER)
        {
          yr_compiler_set_error_extra_info(
              compiler, "wrong type for enumeration item");
          result = ERROR_WRONG_TYPE;
        }

        fail_if_error(result);
      }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 1483 "grammar.y"
    {
        int result = ERROR_SUCCESS;

        if ((yyvsp[(3) - (3)].expression).type != EXPRESSION_TYPE_INTEGER)
        {
          yr_compiler_set_error_extra_info(
              compiler, "wrong type for enumeration item");
          result = ERROR_WRONG_TYPE;
        }

        fail_if_error(result);
      }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 1500 "grammar.y"
    {
        // Push end-of-list marker
        yr_parser_emit_with_arg(yyscanner, OP_PUSH, UNDEFINED, NULL, NULL);
      }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 1506 "grammar.y"
    {
        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_PUSH, UNDEFINED, NULL, NULL));

        fail_if_error(yr_parser_emit_pushes_for_strings(
            yyscanner, "$*"));
      }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 1524 "grammar.y"
    {
        int result = yr_parser_emit_pushes_for_strings(yyscanner, (yyvsp[(1) - (1)].c_string));
        yr_free((yyvsp[(1) - (1)].c_string));

        fail_if_error(result);
      }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 1531 "grammar.y"
    {
        int result = yr_parser_emit_pushes_for_strings(yyscanner, (yyvsp[(1) - (1)].c_string));
        yr_free((yyvsp[(1) - (1)].c_string));

        fail_if_error(result);
      }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 1543 "grammar.y"
    {
        yr_parser_emit_with_arg(yyscanner, OP_PUSH, UNDEFINED, NULL, NULL);
      }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 1547 "grammar.y"
    {
        yr_parser_emit_with_arg(yyscanner, OP_PUSH, 1, NULL, NULL);
      }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 1555 "grammar.y"
    {
        (yyval.expression) = (yyvsp[(2) - (3)].expression);
      }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 1559 "grammar.y"
    {
        fail_if_error(yr_parser_emit(
            yyscanner, OP_FILESIZE, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 1567 "grammar.y"
    {
        yywarning(yyscanner,
            "Using deprecated \"entrypoint\" keyword. Use the \"entry_point\" "
            "function from PE module instead.");

        fail_if_error(yr_parser_emit(
            yyscanner, OP_ENTRYPOINT, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 1579 "grammar.y"
    {
        check_type((yyvsp[(3) - (4)].expression), EXPRESSION_TYPE_INTEGER, "intXXXX or uintXXXX");

        // _INTEGER_FUNCTION_ could be any of int8, int16, int32, uint8,
        // uint32, etc. $1 contains an index that added to OP_READ_INT results
        // in the proper OP_INTXX opcode.

        fail_if_error(yr_parser_emit(
            yyscanner, (uint8_t) (OP_READ_INT + (yyvsp[(1) - (4)].integer)), NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 1593 "grammar.y"
    {
        fail_if_error(yr_parser_emit_with_arg(
            yyscanner, OP_PUSH, (yyvsp[(1) - (1)].integer), NULL, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = (yyvsp[(1) - (1)].integer);
      }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 1601 "grammar.y"
    {
        fail_if_error(yr_parser_emit_with_arg_double(
            yyscanner, OP_PUSH, (yyvsp[(1) - (1)].double_), NULL, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_FLOAT;
      }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 1608 "grammar.y"
    {
        SIZED_STRING* sized_string;

        int result = yr_arena_write_data(
            compiler->sz_arena,
            (yyvsp[(1) - (1)].sized_string),
            (yyvsp[(1) - (1)].sized_string)->length + sizeof(SIZED_STRING),
            (void**) &sized_string);

        yr_free((yyvsp[(1) - (1)].sized_string));

        if (result == ERROR_SUCCESS)
          result = yr_parser_emit_with_arg_reloc(
              yyscanner,
              OP_PUSH,
              sized_string,
              NULL,
              NULL);

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_STRING;
        (yyval.expression).value.sized_string = sized_string;
      }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 1633 "grammar.y"
    {
        int result = yr_parser_reduce_string_identifier(
            yyscanner, (yyvsp[(1) - (1)].c_string), OP_COUNT, UNDEFINED);

        yr_free((yyvsp[(1) - (1)].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 1645 "grammar.y"
    {
        int result = yr_parser_reduce_string_identifier(
            yyscanner, (yyvsp[(1) - (4)].c_string), OP_OFFSET, UNDEFINED);

        yr_free((yyvsp[(1) - (4)].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 1657 "grammar.y"
    {
        int result = yr_parser_emit_with_arg(
            yyscanner, OP_PUSH, 1, NULL, NULL);

        if (result == ERROR_SUCCESS)
          result = yr_parser_reduce_string_identifier(
              yyscanner, (yyvsp[(1) - (1)].c_string), OP_OFFSET, UNDEFINED);

        yr_free((yyvsp[(1) - (1)].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 1673 "grammar.y"
    {
        int result = yr_parser_reduce_string_identifier(
            yyscanner, (yyvsp[(1) - (4)].c_string), OP_LENGTH, UNDEFINED);

        yr_free((yyvsp[(1) - (4)].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 1685 "grammar.y"
    {
        int result = yr_parser_emit_with_arg(
            yyscanner, OP_PUSH, 1, NULL, NULL);

        if (result == ERROR_SUCCESS)
          result = yr_parser_reduce_string_identifier(
              yyscanner, (yyvsp[(1) - (1)].c_string), OP_LENGTH, UNDEFINED);

        yr_free((yyvsp[(1) - (1)].c_string));

        fail_if_error(result);

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = UNDEFINED;
      }
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 1701 "grammar.y"
    {
        int result = ERROR_SUCCESS;

        if ((yyvsp[(1) - (1)].expression).type == EXPRESSION_TYPE_INTEGER)  // loop identifier
        {
          (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
          (yyval.expression).value.integer = UNDEFINED;
        }
        else if ((yyvsp[(1) - (1)].expression).type == EXPRESSION_TYPE_BOOLEAN)  // rule identifier
        {
          (yyval.expression).type = EXPRESSION_TYPE_BOOLEAN;
          (yyval.expression).value.integer = UNDEFINED;
        }
        else if ((yyvsp[(1) - (1)].expression).type == EXPRESSION_TYPE_OBJECT)
        {
          result = yr_parser_emit(
              yyscanner, OP_OBJ_VALUE, NULL);

          switch((yyvsp[(1) - (1)].expression).value.object->type)
          {
            case OBJECT_TYPE_INTEGER:
              (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
              (yyval.expression).value.integer = UNDEFINED;
              break;
            case OBJECT_TYPE_FLOAT:
              (yyval.expression).type = EXPRESSION_TYPE_FLOAT;
              break;
            case OBJECT_TYPE_STRING:
              (yyval.expression).type = EXPRESSION_TYPE_STRING;
              (yyval.expression).value.sized_string = NULL;
              break;
            default:
              yr_compiler_set_error_extra_info_fmt(
                  compiler,
                  "wrong usage of identifier \"%s\"",
                  (yyvsp[(1) - (1)].expression).identifier);
              result = ERROR_WRONG_TYPE;
          }
        }
        else
        {
          assert(false);
        }

        fail_if_error(result);
      }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 1748 "grammar.y"
    {
        int result = ERROR_SUCCESS;

        check_type((yyvsp[(2) - (2)].expression), EXPRESSION_TYPE_INTEGER | EXPRESSION_TYPE_FLOAT, "-");

        if ((yyvsp[(2) - (2)].expression).type == EXPRESSION_TYPE_INTEGER)
        {
          (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
          (yyval.expression).value.integer = ((yyvsp[(2) - (2)].expression).value.integer == UNDEFINED) ?
              UNDEFINED : -((yyvsp[(2) - (2)].expression).value.integer);
          result = yr_parser_emit(yyscanner, OP_INT_MINUS, NULL);
        }
        else if ((yyvsp[(2) - (2)].expression).type == EXPRESSION_TYPE_FLOAT)
        {
          (yyval.expression).type = EXPRESSION_TYPE_FLOAT;
          result = yr_parser_emit(yyscanner, OP_DBL_MINUS, NULL);
        }

        fail_if_error(result);
      }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 1769 "grammar.y"
    {
        int result = yr_parser_reduce_operation(
            yyscanner, "+", (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));

        if ((yyvsp[(1) - (3)].expression).type == EXPRESSION_TYPE_INTEGER &&
            (yyvsp[(3) - (3)].expression).type == EXPRESSION_TYPE_INTEGER)
        {
          int64_t i1 = (yyvsp[(1) - (3)].expression).value.integer;
          int64_t i2 = (yyvsp[(3) - (3)].expression).value.integer;

          if (!IS_UNDEFINED(i1) && !IS_UNDEFINED(i2) &&
              (
                (i2 > 0 && i1 > INT64_MAX - i2) ||
                (i2 < 0 && i1 < INT64_MIN - i2)
              ))
          {
            yr_compiler_set_error_extra_info_fmt(
                compiler, "%" PRId64 " + %" PRId64, i1, i2);

            result = ERROR_INTEGER_OVERFLOW;
          }
          else
          {
            (yyval.expression).value.integer = OPERATION(+, i1, i2);
            (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
          }
        }
        else
        {
          (yyval.expression).type = EXPRESSION_TYPE_FLOAT;
        }

        fail_if_error(result);
      }
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 1804 "grammar.y"
    {
        int result = yr_parser_reduce_operation(
            yyscanner, "-", (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));

        if ((yyvsp[(1) - (3)].expression).type == EXPRESSION_TYPE_INTEGER &&
            (yyvsp[(3) - (3)].expression).type == EXPRESSION_TYPE_INTEGER)
        {
          int64_t i1 = (yyvsp[(1) - (3)].expression).value.integer;
          int64_t i2 = (yyvsp[(3) - (3)].expression).value.integer;

          if (!IS_UNDEFINED(i1) && !IS_UNDEFINED(i2) &&
              (
                (i2 < 0 && i1 > INT64_MAX + i2) ||
                (i2 > 0 && i1 < INT64_MIN + i2)
              ))
          {
            yr_compiler_set_error_extra_info_fmt(
                compiler, "%" PRId64 " - %" PRId64, i1, i2);

            result = ERROR_INTEGER_OVERFLOW;
          }
          else
          {
            (yyval.expression).value.integer = OPERATION(-, i1, i2);
            (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
          }
        }
        else
        {
          (yyval.expression).type = EXPRESSION_TYPE_FLOAT;
        }

        fail_if_error(result);
      }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 1839 "grammar.y"
    {
        int result = yr_parser_reduce_operation(
            yyscanner, "*", (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));

        if ((yyvsp[(1) - (3)].expression).type == EXPRESSION_TYPE_INTEGER &&
            (yyvsp[(3) - (3)].expression).type == EXPRESSION_TYPE_INTEGER)
        {
          int64_t i1 = (yyvsp[(1) - (3)].expression).value.integer;
          int64_t i2 = (yyvsp[(3) - (3)].expression).value.integer;

          if (!IS_UNDEFINED(i1) && !IS_UNDEFINED(i2) &&
              (
                i2 != 0 && llabs(i1) > INT64_MAX / llabs(i2)
              ))
          {
            yr_compiler_set_error_extra_info_fmt(
                compiler, "%" PRId64 " * %" PRId64, i1, i2);

            result = ERROR_INTEGER_OVERFLOW;
          }
          else
          {
            (yyval.expression).value.integer = OPERATION(*, i1, i2);
            (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
          }
        }
        else
        {
          (yyval.expression).type = EXPRESSION_TYPE_FLOAT;
        }

        fail_if_error(result);
      }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 1873 "grammar.y"
    {
        int result = yr_parser_reduce_operation(
            yyscanner, "\\", (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));

        if ((yyvsp[(1) - (3)].expression).type == EXPRESSION_TYPE_INTEGER &&
            (yyvsp[(3) - (3)].expression).type == EXPRESSION_TYPE_INTEGER)
        {
          if ((yyvsp[(3) - (3)].expression).value.integer != 0)
          {
            (yyval.expression).value.integer = OPERATION(/, (yyvsp[(1) - (3)].expression).value.integer, (yyvsp[(3) - (3)].expression).value.integer);
            (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
          }
          else
          {
            result = ERROR_DIVISION_BY_ZERO;
          }
        }
        else
        {
          (yyval.expression).type = EXPRESSION_TYPE_FLOAT;
        }

        fail_if_error(result);
      }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 1898 "grammar.y"
    {
        check_type((yyvsp[(1) - (3)].expression), EXPRESSION_TYPE_INTEGER, "%");
        check_type((yyvsp[(3) - (3)].expression), EXPRESSION_TYPE_INTEGER, "%");

        fail_if_error(yr_parser_emit(yyscanner, OP_MOD, NULL));

        if ((yyvsp[(3) - (3)].expression).value.integer != 0)
        {
          (yyval.expression).value.integer = OPERATION(%, (yyvsp[(1) - (3)].expression).value.integer, (yyvsp[(3) - (3)].expression).value.integer);
          (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        }
        else
        {
          fail_if_error(ERROR_DIVISION_BY_ZERO);
        }
      }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 1915 "grammar.y"
    {
        check_type((yyvsp[(1) - (3)].expression), EXPRESSION_TYPE_INTEGER, "^");
        check_type((yyvsp[(3) - (3)].expression), EXPRESSION_TYPE_INTEGER, "^");

        fail_if_error(yr_parser_emit(yyscanner, OP_BITWISE_XOR, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = OPERATION(^, (yyvsp[(1) - (3)].expression).value.integer, (yyvsp[(3) - (3)].expression).value.integer);
      }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 1925 "grammar.y"
    {
        check_type((yyvsp[(1) - (3)].expression), EXPRESSION_TYPE_INTEGER, "^");
        check_type((yyvsp[(3) - (3)].expression), EXPRESSION_TYPE_INTEGER, "^");

        fail_if_error(yr_parser_emit(yyscanner, OP_BITWISE_AND, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = OPERATION(&, (yyvsp[(1) - (3)].expression).value.integer, (yyvsp[(3) - (3)].expression).value.integer);
      }
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 1935 "grammar.y"
    {
        check_type((yyvsp[(1) - (3)].expression), EXPRESSION_TYPE_INTEGER, "|");
        check_type((yyvsp[(3) - (3)].expression), EXPRESSION_TYPE_INTEGER, "|");

        fail_if_error(yr_parser_emit(yyscanner, OP_BITWISE_OR, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = OPERATION(|, (yyvsp[(1) - (3)].expression).value.integer, (yyvsp[(3) - (3)].expression).value.integer);
      }
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 1945 "grammar.y"
    {
        check_type((yyvsp[(2) - (2)].expression), EXPRESSION_TYPE_INTEGER, "~");

        fail_if_error(yr_parser_emit(yyscanner, OP_BITWISE_NOT, NULL));

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;
        (yyval.expression).value.integer = ((yyvsp[(2) - (2)].expression).value.integer == UNDEFINED) ?
            UNDEFINED : ~((yyvsp[(2) - (2)].expression).value.integer);
      }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 1955 "grammar.y"
    {
        int result;

        check_type((yyvsp[(1) - (3)].expression), EXPRESSION_TYPE_INTEGER, "<<");
        check_type((yyvsp[(3) - (3)].expression), EXPRESSION_TYPE_INTEGER, "<<");

        result = yr_parser_emit(yyscanner, OP_SHL, NULL);

        if (!IS_UNDEFINED((yyvsp[(3) - (3)].expression).value.integer) && (yyvsp[(3) - (3)].expression).value.integer < 0)
          result = ERROR_INVALID_OPERAND;
        else if (!IS_UNDEFINED((yyvsp[(3) - (3)].expression).value.integer) && (yyvsp[(3) - (3)].expression).value.integer >= 64)
          (yyval.expression).value.integer = 0;
        else
          (yyval.expression).value.integer = OPERATION(<<, (yyvsp[(1) - (3)].expression).value.integer, (yyvsp[(3) - (3)].expression).value.integer);

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;

        fail_if_error(result);
      }
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 1975 "grammar.y"
    {
        int result;

        check_type((yyvsp[(1) - (3)].expression), EXPRESSION_TYPE_INTEGER, ">>");
        check_type((yyvsp[(3) - (3)].expression), EXPRESSION_TYPE_INTEGER, ">>");

        result = yr_parser_emit(yyscanner, OP_SHR, NULL);

        if (!IS_UNDEFINED((yyvsp[(3) - (3)].expression).value.integer) && (yyvsp[(3) - (3)].expression).value.integer < 0)
          result = ERROR_INVALID_OPERAND;
        else if (!IS_UNDEFINED((yyvsp[(3) - (3)].expression).value.integer) && (yyvsp[(3) - (3)].expression).value.integer >= 64)
          (yyval.expression).value.integer = 0;
        else
          (yyval.expression).value.integer = OPERATION(<<, (yyvsp[(1) - (3)].expression).value.integer, (yyvsp[(3) - (3)].expression).value.integer);

        (yyval.expression).type = EXPRESSION_TYPE_INTEGER;

        fail_if_error(result);
      }
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 1995 "grammar.y"
    {
        (yyval.expression) = (yyvsp[(1) - (1)].expression);
      }
    break;


/* Line 1792 of yacc.c  */
#line 3926 "grammar.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (yyscanner, compiler, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yyscanner, compiler, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, yyscanner, compiler);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yyscanner, compiler);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (yyscanner, compiler, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, yyscanner, compiler);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yyscanner, compiler);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 2000 "grammar.y"

