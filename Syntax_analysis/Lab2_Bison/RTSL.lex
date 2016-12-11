/* Exercise 1: Lexical Analysis*/
/* Group Number: AB */
/* Group Members:
 * Jiawen Wang  387557
 * Shaolei Wang 387561
 * Zhiwei Liu   387571
 */
%option noyywrap
%{
#include <stdio.h>
#include <math.h>
#include "RTSL.yy.h"
int linenumber = 1;
%}
var_name [a-zA-Z][_a-zA-Z0-9]*
digit [0-9]
hex_digit 0[xX][0-9A-Fa-f]+ 
oct_digit 0{digit}+
/* block_comment \/\*([^\/]|[^\*]\/)*\*\/ 
   this expression works well for recognizing blockcomments. However, for this expression, it's unable to count the line numbers inside the block. So I don't use this.
*/
line_comment \/\/.*$
%x C_BLOCK_COMMENT
float_digit ({digit}*"."{digit}+)|({digit}+"."{digit}*)|({digit}+"."{digit}+)
float_digit_with_exponent ({float_digit}|{digit}+)[eE](\+|-)?{digit}+
%%


"/*"                  { BEGIN(C_BLOCK_COMMENT); }
<C_BLOCK_COMMENT>"*/" { BEGIN(INITIAL); }
<C_BLOCK_COMMENT>\n   { linenumber++;}
<C_BLOCK_COMMENT>.    { }

{line_comment} {}

({float_digit_with_exponent}|{float_digit})(f|lf|F|LF)? { return(F_CONSTANT);}

(({hex_digit}+)|({oct_digit})|({digit}+))(u|U)? { return(I_CONSTANT);}

"int" {return(INT);}
"float" {return(FLOAT);}
"bool" {return(BOOL);}
"void" {return(VOID);}
"vec2" {return(VEC2);}
"vec3" {return(VEC3);}
"vec4" {return(VEC4);}
"bvec2" {return(BVEC2);}
"bvec3" {return(BVEC3);}
"bvec4" {return(BVEC4);}
"color" {return(COLOR);}
"rt_Primitive" {return(PRIMITIVE);}
"rt_Camera" {return(CAMERA);}
"rt_Material" {return (MATERIAL);}
"rt_Texture" {return(TEXTURE);}
"rt_Light" {return(LIGHT);}

"public" {return(PUBLIC);}
"private" {return(PRIVATE);}

"class" {return(CLASS);}
"if" {return(IF);}
"else" {return(ELSE);}
"while" {return(WHILE);}
"for" {return(FOR);}

"++" { return(INC);}
"--" { return(DEC);}
"+" { return(PLUS);}
"*" { return(MUL);}
"-" { return(MINUS);}
"/" { return(DIV);}
"=" { return(ASSIGN);}
"+=" { return(PLUS_ASSIGN);}
"-=" { return(MINUS_ASSIGN);}
"*=" { return(MUL_ASSIGN);}
"/=" { return(DIV_ASSIGN);}
"%=" { return(MOD_ASSIGN);}
"==" { return(EQUAL);}
"!=" { return(NOT_EQUAL);}
"<" { return(LT);}
"<=" { return(LE);}
">" { return(GT);}
">=" { return(GE);}
"," { return(COMMA);}
":" { return(COLON);}
";" { return(SEMICOLON);}
"(" { return(LPARENTHESIS);}
")" { return(RPARENTHESIS);}
"[" { return(LBRACKET);}
"]" { return(RBRACKET);}
"{" { return(LBRACE);}
"}" { return(RBRACE);}
"&&" { return(AND);}
"||" { return(OR);}
"return" {return(RETURN);}
[\n] { linenumber++; }
[ \t]+ {}
((_)*{var_name}"."(_)*{var_name})|((_)*{var_name}) { return(IDENTIFIER);}
. {printf("ERROR(%d): Unrecognized symbol \"%s\"\n", linenumber, yytext);}
%%

