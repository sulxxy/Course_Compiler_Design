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
  void labeled_statement();
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
  void direct_declarator_left_recursion_eliminated();
  void declaration_list();
  void declaration_list_left_recursion_eliminated();
  void external_declaration();
  void parameter_type_list();
  void parameter_list();
  void parameter_list_left_recursion_eliminated();
  void parameter_declaration();
  void identifier_list();
  void identifier_list_left_recursion_eliminated();

  // starting
  void translation_unit();
  void translation_unit_left_recursion_eliminated();

  //initializer
  void initializer();
  void initializer_list();

  //operators
  void unary_operator();
  void assignment_operator();

  //expressions
  void primary_expression();
  void postfix_expression();
  void unary_expression();
  void cast_expression();
  void multiplicative_expression();
  void additive_expression();
  void shift_expression();
  void relational_expression();
  void equality_expression();
  void and_expression();
  void exclusive_or_expression();
  void inclusive_and_expresssion();
  void logical_and_expression();
  void logical_or_expression();
  void conditional_expression();
  void assignment_expression();
  void expression();
  void arithmetic_expression();
  void arithmetic_expression_left_recursion_eliminated();
  void term();
  void term_left_recursion_eliminated();
  void factor();
  void empty();

  //block
  void block_item();
  void block_item_list();
  void block_item_list_left_recursion_eliminated();

  //functions
  void function_definition();

  //helper functions
  void match(TokenType);
  void eat();
  bool is_declaration_type(TokenType);
private:
  Scanner m_lexer;
  Token m_lookahead;

};

#endif // PARSER_H
