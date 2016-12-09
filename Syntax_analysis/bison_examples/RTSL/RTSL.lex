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

true\b|false\b { printf("BOOL %s\n", yytext); }

({float_digit_with_exponent}|{float_digit})(f|lf|F|LF)? { printf("FLOAT %s\n", yytext);}

(({hex_digit}+)|({oct_digit})|({digit}+))(u|U)? { printf("INT %s\n", yytext);}


(int|float|bool|void|vec2|vec3|vec4|ivec2|ivec3|ivec4|bvec2|bvec3|bvec4|rt_Primitive|rt_Camera|rt_Material|rt_Texture|rt_Light)\b { printf("TYPE %s\n", yytext); }

(attribute|uniform|varying|const|public|private|scratch)\b { printf("QUALIFIER %s\n", yytext); }

(class|break|case|const|continue|default|do|double|else|enum|extern|for|goto|if|sizeof|static|struct|switch|typedef|union|unsigned|while|illuminance|ambient|dominantAxis|dot|hit|inside|inverse|luminance|max|min|normalize|perpendicularTo|pow|rand|reflect|sqrt|trace)\b { printf("KEYWORD %s\n", yytext);}

rt_{var_name} { printf("STATE %s\n", yytext);}

"."{var_name} { printf("SWIZZLE %s\n", ++yytext);}

"+" { printf("PLUS\n");}
"*" { printf("MUL\n");}
"-" { printf("MINUS\n");}
"/" { printf("DIV\n");}
"=" { printf("ASSIGN\n");}
"==" { printf("EQUAL\n");}
"!=" { printf("NOT_EQUAL\n");}
"<" { printf("LT\n");}
"<=" { printf("LE\n");}
">" { printf("GT\n");}
">=" { printf("GE\n");}
"," { printf("COMMA\n");}
":" { printf("COLON\n");}
";" { printf("SEMICOLON\n");}
"(" { printf("LPARENTHESIS\n");}
")" { printf("RPARENTHESIS\n");}
"[" { printf("LBRACKET\n");}
"]" { printf("RBRACKET\n");}
"{" { printf("LBRACE\n");}
"}" { printf("RBRACE\n");}
"&&" { printf("AND\n");}
"||" { printf("OR\n");}
"++" { printf("INC\n");}
"--" { printf("DEC\n");}
[\n] { linenumber++; }
[ \t]+ {}
(_)*{var_name} { printf("IDENTIFIER %s\n", yytext);}
. {printf("ERROR(%d): Unrecognized symbol \"%s\"\n", linenumber, yytext);}
%%

int main(int argc, char** argv){
	if(argc > 1){
		yyin = fopen(argv[1], "r");
	}
	else{
		yyin = stdin;
	}
	yylex();
	return 0;
}
