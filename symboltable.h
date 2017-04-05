#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

enum TokenType {
  ID = 1,    /* e.g. PI, name */
  LITERAL,   /* e.g. "core dump" */
  NUMBER,

  /* data types */
  BOOL,
  CHAR,
  SHORT,
  VOID,
  INT,
  FLOAT,
  DOUBLE,
  UNSIGNED,
  LONG,


  /* binary operators */
  PLUS,
  MINUS,
  MUL,
  DIV,
  ASSIGN,

  /* COMPARISON, e.g. <, >, <=, !=, == */
  LE,   /* <= */
  GE,   /* >= */
  NE,   /* != */
  LT,   /* < */
  GT,   /* > */
  EQ,   /* == */

  /* keywords */
  IF,
  ELSE,
  WHEN,
  DO,
  WHILE,
  BREAK,
  SWITCH,
  CASE,
  CONTINUE,
  STRUCT,
  ENUM,
  EXTERN,
  INLINE,
  RETURN,

//  CLASS,

  L_PARENTHESIS,  /* ( */
  R_PARENTHESIS,  /* ) */
  L_BRACKET,  /* [ */
  R_BRACKET,  /* ] */
  L_BRACE,  /* { */
  R_BRACE,  /* } */

  /* punctuations */
  COMMA,  /* , */
  COLON,  /* : */
  SEMICOLON, /* ; */

  /* special */
  EOF_TYPE,
  WS,       /* white space, including \t, \n, \r */
  STARTING_TYPE,
  RESERVE
};

struct SymbolTable {

};

#endif // SYMBOLTABLE_H
