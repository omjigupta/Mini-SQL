
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_Create = 258,
     T_Delete = 259,
     T_From = 260,
     T_Table = 261,
     T_Database = 262,
     T_Asterisk = 263,
     T_Select = 264,
     T_Insert = 265,
     T_Values = 266,
     T_Into = 267,
     T_Where = 268,
     T_Drop = 269,
     T_Update = 270,
     T_Set = 271,
     V_Int = 272,
     V_String = 273,
     T_Use = 274,
     D_Int = 275,
     D_Char = 276,
     D_Varchar = 277,
     D_Double = 278,
     D_Boolean = 279,
     D_String = 280,
     D_Date = 281,
     T_OpBrace = 282,
     T_ClBrace = 283,
     T_Comma = 284,
     T_Semicolon = 285,
     T_Quote = 286,
     T_Equal = 287,
     T_And = 288,
     T_Or = 289,
     T_Not = 290,
     T_Name = 291,
     V_Date = 292,
     V_Bool = 293,
     V_Double = 294,
     T_GT = 295,
     T_LT = 296,
     T_GTE = 297,
     T_LTE = 298,
     T_NE = 299,
     C_PK = 300,
     C_FK = 301,
     C_RF = 302,
     C_UQ = 303,
     T_IS = 304,
     T_NULL = 305,
     T_NOTNULL = 306,
     T_Constraint = 307
   };
#endif
/* Tokens.  */
#define T_Create 258
#define T_Delete 259
#define T_From 260
#define T_Table 261
#define T_Database 262
#define T_Asterisk 263
#define T_Select 264
#define T_Insert 265
#define T_Values 266
#define T_Into 267
#define T_Where 268
#define T_Drop 269
#define T_Update 270
#define T_Set 271
#define V_Int 272
#define V_String 273
#define T_Use 274
#define D_Int 275
#define D_Char 276
#define D_Varchar 277
#define D_Double 278
#define D_Boolean 279
#define D_String 280
#define D_Date 281
#define T_OpBrace 282
#define T_ClBrace 283
#define T_Comma 284
#define T_Semicolon 285
#define T_Quote 286
#define T_Equal 287
#define T_And 288
#define T_Or 289
#define T_Not 290
#define T_Name 291
#define V_Date 292
#define V_Bool 293
#define V_Double 294
#define T_GT 295
#define T_LT 296
#define T_GTE 297
#define T_LTE 298
#define T_NE 299
#define C_PK 300
#define C_FK 301
#define C_RF 302
#define C_UQ 303
#define T_IS 304
#define T_NULL 305
#define T_NOTNULL 306
#define T_Constraint 307




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


