/* Example 1, Hello-World Lexer */
%option noyywrap

%{
#include <stdio.h>
#include "hello.yy.h" // the output of bison on Hello-World Parser
%}

%%
 
";"           return SEMICOLON ;

"hello-world" { printf("got HELLO token\n"); return HELLO; }

"quit"        { printf("got QUIT token\n"); return QUIT; }

[ \t\n]+      ; // do nothing on whitespace

%%

void yyerror(char *str) { printf("ERROR: Could not parse !\n "); }

int main ( void ) {
  // we don ’t want to do anything extra, just start the parser
  yyparse (); // yyparse is defined for us by bison
}
