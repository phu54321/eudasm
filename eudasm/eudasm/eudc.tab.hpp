
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 1 "eudc.y"

#include "ast.h"
typedef node YYSTYPE;
#define YYSTYPE_IS_DECLARED 1
#define YY_NO_UNISTD_H



/* Line 1676 of yacc.c  */
#line 49 "eudc.tab.hpp"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NAME = 258,
     INTEGER = 259,
     STRING = 260,
     LE = 261,
     GE = 262,
     EQ = 263,
     NE = 264,
     AND = 265,
     OR = 266,
     ADDMOV = 267,
     SUBMOV = 268,
     FDEF = 269,
     FDECL = 270,
     VDEF = 271,
     VAR = 272,
     ARRAY = 273,
     FOR = 274,
     WHILE = 275,
     IF = 276,
     ELSE = 277,
     CONTINUE = 278,
     BREAK = 279,
     RETURN = 280,
     YIELD = 281,
     CONCAT = 282,
     DECR = 283,
     INCR = 284,
     MONIC = 285,
     FUNCTIONCALL = 286,
     ARRSUBSCRIPT = 287
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


