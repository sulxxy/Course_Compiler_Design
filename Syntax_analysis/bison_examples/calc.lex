/* Example 2, Calculator Lexer */
%option noyywrap

%{
#include "calc.yy.h"
%}

%%
"+"	{ return ADD; }
"-"	{ return SUB; }
"*"	{ return MUL; }
"/"	{ return DIV; }
"|"     { return ABS; }
"("     { return OP; }
")"     { return CP; }
[0-9]+	{ yylval = atoi(yytext); return NUMBER; }

\n      { return EOL; }
"//".*  { /* ignore comments */ }
[ \t]   { /* ignore white space */ }
.	{ fprintf(stderr, "Mystery character %c\n", *yytext); }
%%

