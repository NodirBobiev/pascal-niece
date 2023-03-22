/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INVALID_CHARACTER = 258,
    INTEGER = 259,
    REAL = 260,
    RETURN = 261,
    THEN = 262,
    SEMICOLON = 263,
    NEWLINE = 264,
    INTEGER_LITERAL = 265,
    BOOLEAN_LITERAL = 266,
    REAL_LITERAL = 267,
    IDENTIFIER = 268,
    BOOLEAN = 269,
    RANGE = 270,
    WHILE = 271,
    FOR = 272,
    IF = 273,
    ELSE = 274,
    VAR = 275,
    TYPE = 276,
    ROUTINE = 277,
    END = 278,
    RECORD = 279,
    ARRAY = 280,
    IN = 281,
    REVERSE = 282,
    LOOP = 283,
    IS = 284,
    AND = 285,
    OR = 286,
    XOR = 287,
    NOT = 288,
    ASSIGN = 289,
    COLON = 290,
    COMMA = 291,
    DOT = 292,
    LBRACKET = 293,
    RBRACKET = 294,
    LPAREN = 295,
    RPAREN = 296,
    EQUALS = 297,
    EQUAL = 298,
    NOT_EQUAL = 299,
    LESS_THAN = 300,
    LESS_THAN_EQUAL = 301,
    GREATER_THAN = 302,
    GREATER_THAN_EQUAL = 303,
    PLUS = 304,
    MINUS = 305,
    MULTIPLY = 306,
    DIVIDE = 307,
    MODULO = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
