/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_EXPR_UTIL_EXPR_BISON_H_INCLUDED
# define YY_EXPR_UTIL_EXPR_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int expr_debug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    NUMBER = 259,                  /* NUMBER  */
    MIN = 260,                     /* MIN  */
    MAX = 261,                     /* MAX  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    LITERAL = 264,                 /* LITERAL  */
    D_RATIO = 265,                 /* D_RATIO  */
    SOURCE_COUNT = 266,            /* SOURCE_COUNT  */
    EXPR_ERROR = 267,              /* EXPR_ERROR  */
    NEG = 268,                     /* NEG  */
    NOT = 269                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "util/expr.y"

	double	 num;
	char	*str;
	struct ids {
		/*
		 * When creating ids, holds the working set of event ids. NULL
		 * implies the set is empty.
		 */
		struct hashmap *ids;
		/*
		 * The metric value. When not creating ids this is the value
		 * read from a counter, a constant or some computed value. When
		 * creating ids the value is either a constant or BOTTOM. NAN is
		 * used as the special BOTTOM value, representing a "set of all
		 * values" case.
		 */
		double val;
	} ids;

#line 98 "util/expr-bison.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int expr_parse (double *final_val, struct expr_parse_ctx *ctx, bool compute_ids, void *scanner);

#endif /* !YY_EXPR_UTIL_EXPR_BISON_H_INCLUDED  */
