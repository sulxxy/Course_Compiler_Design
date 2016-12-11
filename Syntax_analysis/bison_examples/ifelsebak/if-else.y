%{
#include <stdio.h>
extern int yylex();
void yyerror(const char *s);
%}

%token	IDENTIFIER I_CONSTANT F_CONSTANT STRING_LITERAL FUNC_NAME SIZEOF
%token	PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token	AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token	SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token	XOR_ASSIGN OR_ASSIGN
%token	TYPEDEF_NAME ENUMERATION_CONSTANT

%token	TYPEDEF EXTERN STATIC AUTO REGISTER INLINE
%token	CONST RESTRICT VOLATILE
%token	BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token	COMPLEX IMAGINARY 
%token	STRUCT UNION ENUM ELLIPSIS

%token	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token	ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL

%token A B C D E EA
%start selection_statement
%%

expression
	: EA {printf("EA\n");}
statement
	: A';' {printf("A\n");}
	| B';' {printf("B\n");}
	| C';' {printf("C\n");}
	| D';' {printf("D\n");}
	| E';' {printf("E\n");}
	| selection_statement
	;

selection_statement
	: IF '(' expression ')' statement ELSE statement {printf("IF-ELSE\n"); }
	;

%%

int main(){
	printf("> ");
	yyparse();
}

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}
