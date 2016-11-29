/* Example 1, Hello-World Parser */
%{
#include <stdio.h>
#include <stdlib.h>

// Declare functions defined by the lexer
extern int yylex();
extern void yyerror(char *);
%}
 
/* list the supported tokens */
%token QUIT HELLO SEMICOLON

/* indicate which of the below nodes is the root of the parse tree
 * (defaults to first rule) */
%start root_node

%%

root_node:  hello_node root_node | quit_node;

hello_node: HELLO SEMICOLON 
  { printf ( "parsed a hello node !\nHello, user !\n");};

quit_node:  QUIT SEMICOLON
  { printf ( "parsed a quit node !\nGoodbye, user !\n"); exit (0);};
