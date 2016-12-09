/* Example 2, Simple Calculator Parser */
%{
#include <stdio.h>

extern int yylex(); // Declared by lexer
void yyerror(const char *s); // Declared later in file
%}

/* declare tokens */
%token NUMBER
%token ADD SUB MUL DIV ABS
%token OP CP
%token EOL

%%

calclist: /* nothing */
 | calclist exp EOL { printf("= %d\n> ", $2); }
 | calclist EOL { printf("> "); } /* blank line or a comment */
 ;

exp: factor
 | exp ADD exp { $$ = $1 + $3;  printf("ADD\n");}
 | exp SUB factor { $$ = $1 - $3; printf("SUB\n");}
 ;

factor: term
 | factor MUL term { $$ = $1 * $3; printf("MUL\n");}
 | factor DIV term { $$ = $1 / $3; printf("DIV\n");}
 ;

term: NUMBER {printf("%d\n", $1);}
 | ABS exp ABS { $$ = $2 >= 0 ? $2 : - $2; }
 | OP exp CP { $$ = $2; }
 ;
%%
int main()
{
  printf("> "); 
  yyparse();
}

void yyerror(const char *s)
{
  fprintf(stderr, "error: %s\n", s);
}
