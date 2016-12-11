/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     I_CONSTANT = 259,
     F_CONSTANT = 260,
     STRING_LITERAL = 261,
     FUNC_NAME = 262,
     SIZEOF = 263,
     LBRACE = 264,
     RBRACE = 265,
     LPARENTHESIS = 266,
     RPARENTHESIS = 267,
     LBRACKET = 268,
     RBRACKET = 269,
     COMMA = 270,
     SEMICOLON = 271,
     COLON = 272,
     ASSIGN = 273,
     LT = 274,
     LE = 275,
     GT = 276,
     GE = 277,
     EQUAL = 278,
     NOT_EQUAL = 279,
     PLUS = 280,
     MINUS = 281,
     MUL = 282,
     DIV = 283,
     PTR_OP = 284,
     INC = 285,
     DEC = 286,
     LEFT_OP = 287,
     RIGHT_OP = 288,
     AND = 289,
     OR = 290,
     MUL_ASSIGN = 291,
     DIV_ASSIGN = 292,
     MOD_ASSIGN = 293,
     PLUS_ASSIGN = 294,
     MINUS_ASSIGN = 295,
     SUB_ASSIGN = 296,
     LEFT_ASSIGN = 297,
     RIGHT_ASSIGN = 298,
     AND_ASSIGN = 299,
     CONST = 300,
     RESTRICT = 301,
     VOLATILE = 302,
     PUBLIC = 303,
     PRIVATE = 304,
     BOOL = 305,
     CHAR = 306,
     SHORT = 307,
     INT = 308,
     LONG = 309,
     SIGNED = 310,
     UNSIGNED = 311,
     FLOAT = 312,
     DOUBLE = 313,
     VOID = 314,
     VEC2 = 315,
     VEC3 = 316,
     VEC4 = 317,
     BVEC2 = 318,
     BVEC3 = 319,
     BVEC4 = 320,
     CLASS = 321,
     COLOR = 322,
     IF = 323,
     ELSE = 324,
     RETURN = 325,
     WHILE = 326,
     FOR = 327,
     PRIMITIVE = 328,
     CAMERA = 329,
     MATERIAL = 330,
     TEXTURE = 331,
     LIGHT = 332
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define I_CONSTANT 259
#define F_CONSTANT 260
#define STRING_LITERAL 261
#define FUNC_NAME 262
#define SIZEOF 263
#define LBRACE 264
#define RBRACE 265
#define LPARENTHESIS 266
#define RPARENTHESIS 267
#define LBRACKET 268
#define RBRACKET 269
#define COMMA 270
#define SEMICOLON 271
#define COLON 272
#define ASSIGN 273
#define LT 274
#define LE 275
#define GT 276
#define GE 277
#define EQUAL 278
#define NOT_EQUAL 279
#define PLUS 280
#define MINUS 281
#define MUL 282
#define DIV 283
#define PTR_OP 284
#define INC 285
#define DEC 286
#define LEFT_OP 287
#define RIGHT_OP 288
#define AND 289
#define OR 290
#define MUL_ASSIGN 291
#define DIV_ASSIGN 292
#define MOD_ASSIGN 293
#define PLUS_ASSIGN 294
#define MINUS_ASSIGN 295
#define SUB_ASSIGN 296
#define LEFT_ASSIGN 297
#define RIGHT_ASSIGN 298
#define AND_ASSIGN 299
#define CONST 300
#define RESTRICT 301
#define VOLATILE 302
#define PUBLIC 303
#define PRIVATE 304
#define BOOL 305
#define CHAR 306
#define SHORT 307
#define INT 308
#define LONG 309
#define SIGNED 310
#define UNSIGNED 311
#define FLOAT 312
#define DOUBLE 313
#define VOID 314
#define VEC2 315
#define VEC3 316
#define VEC4 317
#define BVEC2 318
#define BVEC3 319
#define BVEC4 320
#define CLASS 321
#define COLOR 322
#define IF 323
#define ELSE 324
#define RETURN 325
#define WHILE 326
#define FOR 327
#define PRIMITIVE 328
#define CAMERA 329
#define MATERIAL 330
#define TEXTURE 331
#define LIGHT 332




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

