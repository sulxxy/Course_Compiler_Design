#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

enum TokenType {
  ID = 1,    /* e.g. PI, name */
  LITERAL,   /* e.g. "core dump" */
  NUMBER,

  BOOL,
  CHAR,
  VOID,
  INT,
  FLOAT,
  DOUBLE,
  UNSIGNED,

  COMPARISON, /* e.g. <, >, <=, !=, == */

  PLUS,
  MINUS,
  MUL,
  DIV,
  ASSIGN,

  IF,
  ELSE,
  WHEN,
  BREAK,
  SWITCH,
  CASE,
  CLASS,

  L_PARENTHESIS,  /* ( */
  R_PARENTHESIS,  /* ) */
  L_BRACKET,  /* [ */
  R_BRACKET,  /* ] */
  L_BRACE,  /* { */
  R_BRACE,  /* } */

  COMMA,  /* , */
  COLON,  /* : */
  SEMICOLON, /* ; */

  EOF_TYPE
};

struct SymbolTable {

};

#endif // SYMBOLTABLE_H
