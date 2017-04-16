#ifndef PARSER_H
#define PARSER_H

#include "scanner.h"
#include "utils.h"

class Parser
{
public:
  //constructor
  Parser(const Scanner&);


  //statements
  void primary_statement();
  void compound_statement();
  void selection_statement();
  void iteration_statement();
  void jump_statement();
  void expression_statement();

  //specifiers
  void declaration_specifiers();
  void type_specifier();
  void storage_class_specifier();
  void function_specifier();

  //declaration
  void declaration();
  void init_declarator_list();
  void init_declarator_list_left_recursion_eliminated();
  void init_declarator();
  void declarator();
  void direct_declarator();
  void declaration_list();
  void external_declaration();
  void translation_unit();

  //expression
  void expression();
  void arithmetic_expression();
  void arithmetic_expression_left_recursion_eliminated();
  void term();
  void term_left_recursion_eliminated();
  void recursion();
  void empty();

  //block
  void block_item();
  void block_item_list();

  //functions
  void function_definition();
  void function_declaration();


  //helper functions
  void match(TokenType);
  void eat();
private:
  Scanner m_lexer;
  Token m_lookahead;

};

#endif // PARSER_H
