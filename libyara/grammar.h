/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
     _DOT_DOT_ = 258,
     _RULE_ = 259,
     _PRIVATE_ = 260,
     _GLOBAL_ = 261,
     _META_ = 262,
     _STRINGS_ = 263,
     _CONDITION_ = 264,
     _IDENTIFIER_ = 265,
     _STRING_IDENTIFIER_ = 266,
     _STRING_COUNT_ = 267,
     _STRING_OFFSET_ = 268,
     _STRING_LENGTH_ = 269,
     _STRING_IDENTIFIER_WITH_WILDCARD_ = 270,
     _NUMBER_ = 271,
     _DOUBLE_ = 272,
     _INTEGER_FUNCTION_ = 273,
     _TEXT_STRING_ = 274,
     _HEX_STRING_ = 275,
     _REGEXP_ = 276,
     _ASCII_ = 277,
     _WIDE_ = 278,
     _NOCASE_ = 279,
     _LEET_ = 280,
     _FULLWORD_ = 281,
     _AT_ = 282,
     _FILESIZE_ = 283,
     _ENTRYPOINT_ = 284,
     _ALL_ = 285,
     _ANY_ = 286,
     _IN_ = 287,
     _OF_ = 288,
     _FOR_ = 289,
     _THEM_ = 290,
     _MATCHES_ = 291,
     _CONTAINS_ = 292,
     _IMPORT_ = 293,
     _TRUE_ = 294,
     _FALSE_ = 295,
     _OR_ = 296,
     _AND_ = 297,
     _NEQ_ = 298,
     _EQ_ = 299,
     _GE_ = 300,
     _GT_ = 301,
     _LE_ = 302,
     _LT_ = 303,
     _SHIFT_RIGHT_ = 304,
     _SHIFT_LEFT_ = 305,
     UNARY_MINUS = 306,
     _NOT_ = 307
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 205 "grammar.y"

  EXPRESSION      expression;
  SIZED_STRING*   sized_string;
  char*           c_string;
  int64_t         integer;
  double          double_;
  YR_STRING*      string;
  YR_META*        meta;
  YR_RULE*        rule;


/* Line 2058 of yacc.c  */
#line 121 "grammar.h"
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
