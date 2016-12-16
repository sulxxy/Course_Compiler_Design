/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     LIGHT = 332,
     RAYORIGIN = 333,
     RAYDIRECTION = 334,
     INVERSERAYDIRECTION = 335,
     EPSILON = 336,
     HITDISTANCE = 337,
     SCREENCOORD = 338,
     LENSCOORD = 339,
     DU = 340,
     DV = 341,
     TIMESEED = 342,
     BOUNDMIN = 343,
     BOUNDMAX = 344,
     DPDU = 345,
     DPDV = 346,
     SHADINGNORMAL = 347,
     TEXTUREUV = 348,
     TEXTUREUVW = 349,
     DSDU = 350,
     DSDV = 351,
     PDF = 352,
     TEXTURECOLOR = 353,
     FLOATTEXTUREVALUE = 354,
     DTDU = 355,
     DTDV = 356,
     LIGHTDISTANCE = 357,
     LIGHTCOLOR = 358,
     EMISSIONCOLOR = 359,
     BSDFSEED = 360,
     SAMPLECOLOR = 361,
     BSDFVALUE = 362,
     HITPOINT = 363,
     GEOMETRICNORMAL = 364,
     LIGHTDIRECTION = 365,
     INTERFACE_GENERATERAY = 366,
     INTERFACE_INTERSECT = 367,
     INTERFACE_COMPUTEBOUNDS = 368,
     INTERFACE_COMPUTENORMAL = 369,
     INTERFACE_COMPUTETEXTURECOORDINATES = 370,
     INTERFACE_COMPUTEDERIVATIVES = 371,
     INTERFACE_GENERATESAMPLE = 372,
     INTERFACE_SAMPLEPDF = 373,
     INTERFACE_LOOKUP = 374,
     INTERFACE_SHADE = 375,
     INTERFACE_BSDF = 376,
     INTERFACE_SAMPLEBSDF = 377,
     INTERFACE_EVALUATEPDF = 378,
     INTERFACE_EMISSION = 379,
     INTERFACE_ILLUMINATION = 380
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
#define RAYORIGIN 333
#define RAYDIRECTION 334
#define INVERSERAYDIRECTION 335
#define EPSILON 336
#define HITDISTANCE 337
#define SCREENCOORD 338
#define LENSCOORD 339
#define DU 340
#define DV 341
#define TIMESEED 342
#define BOUNDMIN 343
#define BOUNDMAX 344
#define DPDU 345
#define DPDV 346
#define SHADINGNORMAL 347
#define TEXTUREUV 348
#define TEXTUREUVW 349
#define DSDU 350
#define DSDV 351
#define PDF 352
#define TEXTURECOLOR 353
#define FLOATTEXTUREVALUE 354
#define DTDU 355
#define DTDV 356
#define LIGHTDISTANCE 357
#define LIGHTCOLOR 358
#define EMISSIONCOLOR 359
#define BSDFSEED 360
#define SAMPLECOLOR 361
#define BSDFVALUE 362
#define HITPOINT 363
#define GEOMETRICNORMAL 364
#define LIGHTDIRECTION 365
#define INTERFACE_GENERATERAY 366
#define INTERFACE_INTERSECT 367
#define INTERFACE_COMPUTEBOUNDS 368
#define INTERFACE_COMPUTENORMAL 369
#define INTERFACE_COMPUTETEXTURECOORDINATES 370
#define INTERFACE_COMPUTEDERIVATIVES 371
#define INTERFACE_GENERATESAMPLE 372
#define INTERFACE_SAMPLEPDF 373
#define INTERFACE_LOOKUP 374
#define INTERFACE_SHADE 375
#define INTERFACE_BSDF 376
#define INTERFACE_SAMPLEBSDF 377
#define INTERFACE_EVALUATEPDF 378
#define INTERFACE_EMISSION 379
#define INTERFACE_ILLUMINATION 380




/* Copy the first part of user declarations.  */
#line 1 "RTSL.y"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#define true 1
//#define false 0
extern int yylex();
extern FILE* yyin;
extern char* yytext;
void yyerror(const char *s);

char* STATES_NAME[] = {"camera", "primitive", "texture", "material", "light"};
char* current_shader = NULL;
int index_of_shader = 0;
bool ignore_the_error_inside_interface = false;
char* Camera_states[] = {"rt_RayOrigin", "rt_RayDirection", "rt_InverseRayDirection" , "rt_Epsilon"  , "rt_HitDistance" , "rt_ScreenCoord" , "rt_LensCoord", "rt_du", "rt_dv", "rt_TimeSeed", "generateRay" };
char* Primitive_states[] = {"rt_RayOrigin", "rt_RayDirection" , "rt_InverseRayDirection " , "rt_Epsilon", "rt_HitDistance" , "rt_BoundMin" , "rt_BoundMax" , "rt_GeometricNormal " , "rt_dPdu" , "rt_dPdv" , "rt_ShadingNormal " , "rt_TextureUV" , "rt_TextureUVW", "rt_dsdu", "rt_dsdv", "rt_PDF", "rt_TimeSeed", "intersect" ,"computeBounds" ,"computeNormal" ,"computeTextureCoordinates" ,"computeDerivatives" ,"generateSample" ,"samplePDF" };
char* Texture_states[] = {"rt_TextureUV"  , "rt_TextureUVW " , "rt_TextureColor " , "rt_FloatTextureValue " , "rt_du" , "rt_dv" , "rt_dsdu"  , "rt_dtdu" , "rt_dsdv" , "rt_dtdv" , "rt_dPdu " , "rt_dPdv " , "rt_TimeSeed", "lookup" }; char* Material_states[] = {"rt_RayOrigin" , "rt_RayDirection" , "rt_InverseRayDirection " , "rt_HitPoint" , "rt_dPdu" , "rt_dPdv" , "rt_LightDirection" , "rt_LightDistance" , "rt_LightColor" , "rt_EmissionColor " , "rt_BSDFSeed" , "rt_TimeSeed" , "rt_PDF" , "rt_SampleColor" , "rt_BSDFValue" , "rt_du" , "rt_dv", "shade" ,"BSDF" ,"sampleBSDF" ,"evaluatePDF" ,"emission" };
char* Light_states[] = {"rt_HitPoint" , "rt_GeometricNormal " , "rt_ShadingNormal " , "rt_LightDirection " , "rt_TimeSeed", "illumination" };

char** All[] = {Camera_states, Primitive_states, Texture_states, Material_states, Light_states};
int State_size[] = {sizeof(Camera_states)/sizeof(Camera_states[0]),
	sizeof(Primitive_states)/sizeof(Primitive_states[0]), 
	sizeof(Texture_states)/sizeof(Texture_states[0]), 
	sizeof(Material_states)/sizeof(Material_states[0]), 
	sizeof(Light_states)/sizeof(Light_states[0])};


/*find current text belongs to which state*/
int get_index(char* text){
	for(int i = 0; i < sizeof(All)/sizeof(All[0]); i++){
		for(int j = 0; j < State_size[i]; j++){
			//printf("%d, %d, %s\n", i, j, All[i][j]);
			if(!strcmp(text, All[i][j])){
				return i;
			}
		}
	}
	return -1;
}

bool is_state_in_current_shader(char* text){
	for(int i = 0; i < State_size[index_of_shader]; i++){
		//printf("TEST: %d, %s, %s, %s\n",index_of_shader, All[index_of_shader][i], current_shader, text);
		if(!strcmp(All[index_of_shader][i], text))
			return true;
	}
	return false;
}

void check_state(char* text){
	char ret[100] = "0";
	//is_state_in_current_shader(text);
	if(!is_state_in_current_shader(text) &&  strcmp(STATES_NAME[get_index(text)],current_shader) ){
		sprintf(ret, "%s cannot access a state of %s", current_shader, STATES_NAME[get_index(text)]);
		yyerror(ret);
	}
}

void check_interface(char* text){
	char ret[100] = "0";
	if(strcmp(STATES_NAME[get_index(text)],current_shader)){
		sprintf(ret, "%s cannot have an interface method of %s", current_shader, STATES_NAME[get_index(text)]);
		ignore_the_error_inside_interface = true;
		yyerror(ret);
	}
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 426 "RTSL.yy.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  101
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1379

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  126
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  157
/* YYNRULES -- Number of states.  */
#define YYNSTATES  218

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   380

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    15,    17,    19,    21,
      23,    25,    27,    29,    31,    33,    35,    37,    39,    41,
      43,    45,    47,    49,    51,    53,    55,    57,    59,    61,
      63,    65,    67,    69,    71,    73,    75,    77,    79,    81,
      83,    85,    87,    89,    91,    93,    95,    97,    99,   105,
     107,   109,   111,   113,   115,   117,   119,   121,   123,   125,
     127,   129,   131,   133,   135,   137,   139,   141,   143,   145,
     147,   149,   151,   153,   155,   157,   159,   161,   163,   165,
     167,   169,   171,   173,   175,   177,   179,   181,   183,   185,
     187,   189,   191,   193,   195,   197,   199,   201,   203,   205,
     207,   209,   211,   213,   216,   218,   221,   223,   226,   230,
     234,   240,   242,   245,   249,   254,   258,   263,   267,   271,
     276,   280,   282,   284,   286,   288,   290,   294,   295,   297,
     299,   301,   303,   305,   307,   309,   311,   314,   319,   327,
     333,   339,   349,   353,   356,   360,   362,   365,   367,   369,
     373,   376,   380,   383,   388,   393,   395,   399
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     127,     0,    -1,   127,   140,    -1,   127,   130,    -1,   127,
     149,    -1,   127,   136,    -1,   130,    -1,   140,    -1,   149,
      -1,   136,    -1,    74,    -1,    73,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,    91,
      -1,    92,    -1,    93,    -1,    94,    -1,    95,    -1,    96,
      -1,    97,    -1,    98,    -1,    99,    -1,   100,    -1,   101,
      -1,   102,    -1,   103,    -1,   104,    -1,   105,    -1,   106,
      -1,   107,    -1,   108,    -1,   109,    -1,   110,    -1,    66,
       3,    17,   128,    16,    -1,    59,    -1,    51,    -1,    52,
      -1,    53,    -1,    54,    -1,    57,    -1,    58,    -1,    55,
      -1,    56,    -1,    50,    -1,    60,    -1,    61,    -1,    62,
      -1,    63,    -1,    64,    -1,    65,    -1,    67,    -1,    66,
      -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,    31,
      -1,    30,    -1,    18,    -1,    39,    -1,    40,    -1,    37,
      -1,    36,    -1,    38,    -1,    23,    -1,    24,    -1,    20,
      -1,    19,    -1,    21,    -1,    22,    -1,    45,    -1,    48,
      -1,    49,    -1,   111,    -1,   112,    -1,   113,    -1,   114,
      -1,   115,    -1,   116,    -1,   117,    -1,   118,    -1,   119,
      -1,   120,    -1,   121,    -1,   122,    -1,   123,    -1,   124,
      -1,   125,    -1,   131,   135,    -1,   131,    -1,   133,   135,
      -1,   133,    -1,   135,     3,    -1,   135,     3,    15,    -1,
     135,     3,    16,    -1,   135,     3,    18,   139,    16,    -1,
     136,    -1,   137,   136,    -1,     3,    11,    12,    -1,     3,
      11,   137,    12,    -1,   134,    11,    12,    -1,   134,    11,
     137,    12,    -1,    11,   138,    12,    -1,   138,    11,    12,
      -1,   138,    11,   137,    12,    -1,   139,   132,   139,    -1,
       3,    -1,     4,    -1,     5,    -1,   152,    -1,   129,    -1,
      11,   139,    12,    -1,    -1,   141,    -1,   142,    -1,   143,
      -1,   144,    -1,   145,    -1,   146,    -1,   151,    -1,    16,
      -1,   139,    16,    -1,     3,    18,   139,    16,    -1,    68,
      11,   139,    12,   140,    69,   140,    -1,    68,    11,   139,
      12,   140,    -1,    71,    11,   139,    12,   140,    -1,    72,
      11,   139,    16,   139,    16,   139,    12,   140,    -1,    70,
     139,    16,    -1,     9,    10,    -1,     9,   147,    10,    -1,
     148,    -1,   147,   148,    -1,   136,    -1,   140,    -1,   135,
     138,   150,    -1,     9,    10,    -1,     9,   147,    10,    -1,
     152,    16,    -1,   131,    11,   153,    12,    -1,     3,    11,
     153,    12,    -1,   139,    -1,   139,    15,   139,    -1,   152,
      15,   139,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   115,   116,   117,   118,   119,   120,   121,
     125,   126,   127,   128,   129,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   169,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   217,   218,   219,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   241,   242,   243,   244,   248,   249,   250,
     251,   255,   256,   261,   262,   263,   264,   265,   266,   267,
     272,   273,   274,   275,   276,   277,   278,   279,   284,   285,
     286,   287,   288,   289,   290,   294,   295,   299,   303,   304,
     308,   309,   313,   317,   318,   322,   323,   327,   328,   332,
     336,   337,   341,   345,   346,   351,   352,   353
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "I_CONSTANT", "F_CONSTANT",
  "STRING_LITERAL", "FUNC_NAME", "SIZEOF", "LBRACE", "RBRACE",
  "LPARENTHESIS", "RPARENTHESIS", "LBRACKET", "RBRACKET", "COMMA",
  "SEMICOLON", "COLON", "ASSIGN", "LT", "LE", "GT", "GE", "EQUAL",
  "NOT_EQUAL", "PLUS", "MINUS", "MUL", "DIV", "PTR_OP", "INC", "DEC",
  "LEFT_OP", "RIGHT_OP", "AND", "OR", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN",
  "RIGHT_ASSIGN", "AND_ASSIGN", "CONST", "RESTRICT", "VOLATILE", "PUBLIC",
  "PRIVATE", "BOOL", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "VOID", "VEC2", "VEC3", "VEC4", "BVEC2", "BVEC3",
  "BVEC4", "CLASS", "COLOR", "IF", "ELSE", "RETURN", "WHILE", "FOR",
  "PRIMITIVE", "CAMERA", "MATERIAL", "TEXTURE", "LIGHT", "RAYORIGIN",
  "RAYDIRECTION", "INVERSERAYDIRECTION", "EPSILON", "HITDISTANCE",
  "SCREENCOORD", "LENSCOORD", "DU", "DV", "TIMESEED", "BOUNDMIN",
  "BOUNDMAX", "DPDU", "DPDV", "SHADINGNORMAL", "TEXTUREUV", "TEXTUREUVW",
  "DSDU", "DSDV", "PDF", "TEXTURECOLOR", "FLOATTEXTUREVALUE", "DTDU",
  "DTDV", "LIGHTDISTANCE", "LIGHTCOLOR", "EMISSIONCOLOR", "BSDFSEED",
  "SAMPLECOLOR", "BSDFVALUE", "HITPOINT", "GEOMETRICNORMAL",
  "LIGHTDIRECTION", "INTERFACE_GENERATERAY", "INTERFACE_INTERSECT",
  "INTERFACE_COMPUTEBOUNDS", "INTERFACE_COMPUTENORMAL",
  "INTERFACE_COMPUTETEXTURECOORDINATES", "INTERFACE_COMPUTEDERIVATIVES",
  "INTERFACE_GENERATESAMPLE", "INTERFACE_SAMPLEPDF", "INTERFACE_LOOKUP",
  "INTERFACE_SHADE", "INTERFACE_BSDF", "INTERFACE_SAMPLEBSDF",
  "INTERFACE_EVALUATEPDF", "INTERFACE_EMISSION", "INTERFACE_ILLUMINATION",
  "$accept", "primary_statement", "rt", "shader_states", "shader_def",
  "type_specifier", "operator", "type_qualifier", "interface",
  "specifier_qualifier_list", "declaration", "declaration_list",
  "declarator", "expression", "statement", "expression_statement",
  "assign_statement", "if_statement", "loop_statement", "return_statement",
  "compound_statement", "block_statement", "block_item",
  "function_definition", "function_body_statement",
  "function_call_statement", "function_call", "parameter_list", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   126,   127,   127,   127,   127,   127,   127,   127,   127,
     128,   128,   128,   128,   128,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   130,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   133,   133,   133,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   135,   135,   135,   135,   136,   136,   136,
     136,   137,   137,   138,   138,   138,   138,   138,   138,   138,
     139,   139,   139,   139,   139,   139,   139,   139,   140,   140,
     140,   140,   140,   140,   140,   141,   141,   142,   143,   143,
     144,   144,   145,   146,   146,   147,   147,   148,   148,   149,
     150,   150,   151,   152,   152,   153,   153,   153
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     2,     3,     3,
       5,     1,     2,     3,     4,     3,     4,     3,     3,     4,
       3,     1,     1,     1,     1,     1,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     7,     5,
       5,     9,     3,     2,     3,     1,     2,     1,     1,     3,
       2,     3,     2,     4,     4,     1,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     127,   121,   122,   123,   127,   127,   135,    85,    86,    87,
      58,    50,    51,    52,    53,    56,    57,    54,    55,    49,
      59,    60,    61,    62,    63,    64,    66,    65,     0,   127,
       0,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   127,   125,     6,   104,   106,
       0,     9,     0,     7,   128,   129,   130,   131,   132,   133,
       8,   134,   124,   127,   127,   143,    66,     0,   147,   148,
     127,   145,   121,     0,     0,   124,     0,   127,     0,   127,
     127,     1,     3,     5,     2,     4,   127,   104,   103,   105,
     107,     0,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     0,     0,   136,
      73,    82,    81,    83,    84,    79,    80,    67,    68,    69,
      70,    72,    71,    77,    76,    78,    74,    75,   127,   152,
     155,   124,     0,     0,   107,   144,   146,   126,     0,     0,
     142,     0,     0,     0,     0,   108,   109,   127,     0,     0,
       0,   127,     0,   149,   120,   127,   127,   154,   137,    11,
      10,    12,    13,    14,     0,   127,   127,   127,   153,   113,
     111,     0,     0,   117,   115,     0,   150,   127,   118,     0,
     156,   157,    48,   139,   140,     0,   114,   112,   110,   116,
     151,   119,   127,   127,   138,     0,   127,   141
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    65,   184,    66,    67,    93,   148,    69,   127,    87,
      88,   191,   128,    72,    89,    74,    75,    76,    77,    78,
      79,    90,    91,    80,   173,    81,    95,   152
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -155
static const yytype_int16 yypact[] =
{
     739,   -10,  -155,  -155,   307,   955,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,    12,  -155,    25,   955,
      31,    52,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,   199,  -155,  -155,    -5,  1289,
       9,  -155,   846,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,     7,   955,   955,  -155,  -155,    16,  -155,  -155,
     415,  -155,    53,    55,   308,  -155,    -6,   955,   949,   955,
     955,  -155,  -155,  -155,  -155,  -155,   955,  1289,  -155,  -155,
       6,    24,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,    58,    -2,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,   955,  -155,
     738,    19,    61,  1055,    23,  -155,  -155,  -155,   -44,   416,
    -155,   524,  1243,    62,  1054,  -155,  -155,   955,    59,    14,
    1077,   523,  1111,  -155,  1339,   955,   955,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,    60,   847,   847,   955,  -155,  -155,
    -155,  1134,  1268,  -155,  -155,  1168,  -155,   631,  -155,  1191,
    1339,  1339,  -155,    11,  -155,  1293,  -155,  -155,  -155,  -155,
    -155,  -155,   847,   955,  -155,   632,   847,  -155
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,  -155,  -155,  -155,    17,    10,  -155,  -155,  -155,     3,
      28,  -154,   -34,     8,     2,  -155,  -155,  -155,  -155,  -155,
    -155,   -90,   -85,    20,  -155,  -155,     0,   -22
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      82,    83,    73,    70,    82,   156,   106,   171,    84,   172,
      68,   158,   110,    94,    68,    96,   195,   164,   199,   154,
     111,   165,   166,   149,   167,   172,   193,   168,    71,   179,
     180,   181,   182,   183,   176,   111,    97,    98,   165,   166,
       7,   167,    99,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    86,    27,   100,    83,    82,   106,   104,    70,   170,
     164,   108,   109,   177,   188,    68,   202,   169,   107,   107,
     212,   197,   102,   151,   163,   105,     0,     0,     0,     0,
      82,   150,   153,   103,     0,     0,     0,     0,     0,     0,
      68,     0,     0,     0,     0,   159,   151,   161,   162,     0,
     108,     0,   156,     0,   150,     0,     0,   107,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
       0,     0,     0,     0,     0,     0,   174,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,     0,   107,   192,     0,     0,     0,     0,
     107,    68,   107,   200,   201,    82,    82,   203,   204,     0,
       0,     0,   190,     0,     0,   205,     0,    82,   190,   101,
     190,   107,     1,     2,     3,   107,     0,    68,     4,   107,
       5,     0,    82,     0,   214,     6,    82,     0,   217,   207,
       0,   215,     0,   207,     0,     0,     0,   207,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,    29,
      30,    31,     0,     0,     0,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       1,     2,     3,     0,     0,     0,     4,    85,     5,     0,
     157,     0,     0,     6,     0,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,   141,   142,
       0,     0,     0,     0,   143,   144,   145,   146,   147,     0,
       0,     0,     7,     0,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    86,    27,    28,     0,    29,    30,    31,
       0,     0,     0,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     1,     2,
       3,     0,     0,     0,     4,   155,     5,     0,   185,     0,
       0,     6,     0,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,   141,   142,     0,     0,
       0,     0,   143,   144,   145,   146,   147,     0,     0,     0,
       7,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    86,    27,    28,     0,    29,    30,    31,     0,     0,
       0,     0,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     1,     2,     3,     0,
       0,     0,     4,   196,     5,     0,   186,     0,     0,     6,
       0,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,   141,   142,     0,     0,     0,     0,
     143,   144,   145,   146,   147,     0,     0,     0,     7,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    86,
      27,    28,     0,    29,    30,    31,     0,     0,     0,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     1,     2,     3,     0,     0,     0,
       4,   210,     5,     0,   216,     0,     0,     6,     0,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,   141,   142,     0,     0,     0,     0,   143,   144,
     145,   146,   147,     0,     0,     0,     7,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    86,    27,    28,
       0,    29,    30,    31,     0,     0,     0,     0,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     1,     2,     3,     0,     0,     0,     4,     0,
       5,     0,     0,   175,     0,     6,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,   141,   142,
       0,     0,     0,     0,   143,   144,   145,   146,   147,     0,
       0,     0,     0,     0,     7,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,    29,
      30,    31,     0,     0,     0,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       1,     2,     3,     0,     0,     0,     4,     0,     5,     0,
       0,     0,   129,     6,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,   141,   142,     0,     0,
       0,     0,   143,   144,   145,   146,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    86,    27,    28,     0,    29,    30,    31,
       0,     0,     0,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    92,     2,
       3,     0,     0,     0,     0,   160,     5,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,   141,
     142,     0,     0,     0,     0,   143,   144,   145,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    86,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   189,     0,     0,     0,
       0,   178,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,   141,   142,     0,     0,   194,
       0,   143,   144,   145,   146,   147,     0,     0,     0,     7,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      86,    27,     7,   198,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    86,    27,     0,   206,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    86,    27,     7,
     209,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      86,    27,     0,   211,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    86,    27,     7,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    86,    27,   187,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,   141,   142,     0,     0,     0,     0,   143,
     144,   145,   146,   147,   208,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,   141,   142,
       0,     0,     0,     0,   143,   144,   145,   146,   147,   213,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,   141,   142,     0,     0,     0,     0,   143,
     144,   145,   146,   147,     7,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    86,    27,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,   141,
     142,     0,     0,     0,     0,   143,   144,   145,   146,   147
};

static const yytype_int16 yycheck[] =
{
       0,    11,     0,     0,     4,    90,    11,     9,    18,    11,
       0,    17,     3,     5,     4,     3,   170,    11,   172,     3,
      11,    15,    16,    16,    18,    11,    12,     3,     0,    73,
      74,    75,    76,    77,    15,    11,    11,    29,    15,    16,
      45,    18,    11,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    11,    11,    65,    11,    65,    65,    11,
      11,    68,    69,    12,    12,    65,    16,   111,    68,    69,
      69,   171,    65,    83,   106,    65,    -1,    -1,    -1,    -1,
      90,    83,    84,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    97,   106,    99,   100,    -1,
     107,    -1,   197,    -1,   106,    -1,    -1,   107,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,   164,   167,    -1,    -1,    -1,    -1,
     170,   171,   172,   175,   176,   185,   186,   185,   186,    -1,
      -1,    -1,   164,    -1,    -1,   187,    -1,   197,   170,     0,
     172,   191,     3,     4,     5,   195,    -1,   197,     9,   199,
      11,    -1,   212,    -1,   212,    16,   216,    -1,   216,   191,
      -1,   213,    -1,   195,    -1,    -1,    -1,   199,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      12,    -1,    -1,    16,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    45,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,     3,     4,
       5,    -1,    -1,    -1,     9,    10,    11,    -1,    12,    -1,
      -1,    16,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      45,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,     3,     4,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,    12,    -1,    -1,    16,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    45,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,     3,     4,     5,    -1,    -1,    -1,
       9,    10,    11,    -1,    12,    -1,    -1,    16,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    31,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    45,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,     3,     4,     5,    -1,    -1,    -1,     9,    -1,
      11,    -1,    -1,    15,    -1,    16,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
       3,     4,     5,    -1,    -1,    -1,     9,    -1,    11,    -1,
      -1,    -1,    16,    16,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,     3,     4,
       5,    -1,    -1,    -1,    -1,    16,    11,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    12,    -1,    -1,    -1,
      -1,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    -1,    -1,    12,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    -1,    45,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    45,    12,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    45,
      12,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    45,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    31,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    45,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     9,    11,    16,    45,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    70,
      71,    72,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   127,   129,   130,   131,   133,
     135,   136,   139,   140,   141,   142,   143,   144,   145,   146,
     149,   151,   152,    11,    18,    10,    66,   135,   136,   140,
     147,   148,     3,   131,   139,   152,     3,    11,   139,    11,
      11,     0,   130,   136,   140,   149,    11,   131,   135,   135,
       3,    11,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   134,   138,    16,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    30,    31,    36,    37,    38,    39,    40,   132,    16,
     139,   152,   153,   139,     3,    10,   148,    12,    17,   139,
      16,   139,   139,   153,    11,    15,    16,    18,     3,   138,
      11,     9,    11,   150,   139,    15,    15,    12,    16,    73,
      74,    75,    76,    77,   128,    12,    12,    16,    12,    12,
     136,   137,   139,    12,    12,   137,    10,   147,    12,   137,
     139,   139,    16,   140,   140,   139,    12,   136,    16,    12,
      10,    12,    69,    16,   140,   139,    12,   140
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



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
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
        case 10:
#line 125 "RTSL.y"
    { printf("SHADER_DEF camera\n"); index_of_shader = 0; current_shader = "camera";;}
    break;

  case 11:
#line 126 "RTSL.y"
    { printf("SHADER_DEF primitive\n"); index_of_shader = 1; current_shader = "primitive";;}
    break;

  case 12:
#line 127 "RTSL.y"
    { printf("SHADER_DEF material\n"); index_of_shader = 2; current_shader = "material";;}
    break;

  case 13:
#line 128 "RTSL.y"
    { printf("SHADER_DEF texture\n"); index_of_shader = 3; current_shader = "texture";;}
    break;

  case 14:
#line 129 "RTSL.y"
    { printf("SHADER_DEF light\n"); index_of_shader = 4; current_shader = "light";;}
    break;

  case 88:
#line 223 "RTSL.y"
    { check_interface(yytext);;}
    break;

  case 89:
#line 224 "RTSL.y"
    { check_interface(yytext);;}
    break;

  case 90:
#line 225 "RTSL.y"
    { check_interface(yytext);;}
    break;

  case 91:
#line 226 "RTSL.y"
    { check_interface(yytext);;}
    break;

  case 92:
#line 227 "RTSL.y"
    { check_interface(yytext);;}
    break;

  case 93:
#line 228 "RTSL.y"
    { check_interface(yytext);;}
    break;

  case 94:
#line 229 "RTSL.y"
    { check_interface(yytext);;}
    break;

  case 95:
#line 230 "RTSL.y"
    { check_interface(yytext);;}
    break;

  case 96:
#line 231 "RTSL.y"
    { check_interface(yytext);;}
    break;

  case 97:
#line 232 "RTSL.y"
    { check_interface(yytext);;}
    break;

  case 98:
#line 233 "RTSL.y"
    { check_interface(yytext);;}
    break;

  case 99:
#line 234 "RTSL.y"
    { check_interface(yytext);;}
    break;

  case 100:
#line 235 "RTSL.y"
    { check_interface(yytext);;}
    break;

  case 101:
#line 236 "RTSL.y"
    { check_interface(yytext);;}
    break;

  case 102:
#line 237 "RTSL.y"
    { check_interface(yytext);;}
    break;

  case 109:
#line 250 "RTSL.y"
    { printf("DECLARATION\n");;}
    break;

  case 110:
#line 251 "RTSL.y"
    { printf("DECLARATION\n");;}
    break;

  case 115:
#line 263 "RTSL.y"
    { ignore_the_error_inside_interface = false;;}
    break;

  case 116:
#line 264 "RTSL.y"
    { ignore_the_error_inside_interface = false;;}
    break;

  case 125:
#line 277 "RTSL.y"
    {check_state(yytext);;}
    break;

  case 135:
#line 294 "RTSL.y"
    { printf("STATEMENT\n"); ;}
    break;

  case 136:
#line 295 "RTSL.y"
    { printf("STATEMENT\n");;}
    break;

  case 137:
#line 299 "RTSL.y"
    { printf("STATEMENT\n");;}
    break;

  case 138:
#line 303 "RTSL.y"
    { printf("IF - ELSE\nSTATEMENT\n");;}
    break;

  case 139:
#line 304 "RTSL.y"
    {printf("IF\nSTATEMENT\n");;}
    break;

  case 140:
#line 308 "RTSL.y"
    { printf("STATEMENT\n");;}
    break;

  case 141:
#line 309 "RTSL.y"
    { printf("STATEMENT\n");;}
    break;

  case 142:
#line 313 "RTSL.y"
    { printf("STATEMENT\n");;}
    break;

  case 143:
#line 317 "RTSL.y"
    { printf("STATEMENT\n");;}
    break;

  case 144:
#line 318 "RTSL.y"
    { printf("STATEMENT\n");;}
    break;

  case 149:
#line 332 "RTSL.y"
    {printf("FUNCTION_DEF\n");;}
    break;

  case 152:
#line 341 "RTSL.y"
    { printf("STATEMENT\n");;}
    break;


/* Line 1267 of yacc.c.  */
#line 2286 "RTSL.yy.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 356 "RTSL.y"


int main(int argc, char** argv){
	if(argc > 1){
		yyin = fopen(argv[1], "r");
	}
	else{
		yyin = stdin;
	}
	yyparse();
}

void yyerror(const char *s){
	fflush(stdout);
	fprintf(stderr, "ERROR: %s\n", s);
}

