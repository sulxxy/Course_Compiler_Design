#include "parser.h"


//constructor
Parser::Parser(const Scanner& s) : m_lexer(s)
{
  m_lookahead = m_lexer.nextToken();
}


//statements
void Parser::primary_statement()
{
}

void Parser::compound_statement()
{

}

void Parser::selection_statement()
{

}

void Parser::iteration_statement()
{

}

void Parser::jump_statement()
{

}

void Parser::expression_statement()
{
  expression();
  match(SEMICOLON);
}


//specifiers
void Parser::declaration_specifiers()
{
  type_specifier();
  /*TODO*/

}

void Parser::type_specifier()
{
  switch(m_lookahead.getTokenType())
  {
    case VOID: case BOOL: case CHAR: case SHORT: case INT: case LONG: case FLOAT: case DOUBLE:
      match(m_lookahead.getTokenType());
      return ;
    default:
      LOG_ERR(__func__, "type_specifier", m_lookahead.getTokenText());
      return ;
  }

}

void Parser::storage_class_specifier()
{

}

void Parser::function_specifier()
{

}


//declaration
void Parser::declaration()
{
  declaration_specifiers();
  if(m_lookahead.getTokenType() == SEMICOLON){
    match(SEMICOLON);
    LOG_DBG(__func__, "got a declaration");      //e.g. int ();
    return;
  }
  else{
    init_declarator_list();
    match(SEMICOLON);
    LOG_DBG(__func__, "got a declaration");     //e.g. int a;
    return ;
  }

}

void Parser::init_declarator_list()
{
  init_declarator();
  init_declarator_list_left_recursion_eliminated();
}

void Parser::init_declarator_list_left_recursion_eliminated()
{
  if(m_lookahead.getTokenType() == COMMA){
    match(COMMA);
    init_declarator();
    init_declarator_list_left_recursion_eliminated();
  }
  else{
    empty();
  }
}

void Parser::init_declarator()
{
  declarator();
  /*TODO: add initializer*/
}

void Parser::declarator()
{
  direct_declarator();
  /*TODO*/
}

void Parser::direct_declarator()
{
  if(m_lookahead.getTokenType() == IDENTIFIER){
    match(IDENTIFIER);
    return;
  }
  else if(m_lookahead.getTokenType() == L_PARENTHESIS){
    declarator();
    match(R_PARENTHESIS);
  }
  else{
    /*TODO*/
  }

}

void Parser::declaration_list()
{

}

void Parser::external_declaration()
{

}

void Parser::translation_unit()
{

}

void Parser::initializer()
{

}

void Parser::initializer_list()
{

}


//operators
void Parser::unary_operator()
{
  switch(m_lookahead.getTokenType()){
  case MUL:case DIV: case PLUS: case MINUS:            /*TODO*/
    match(m_lookahead.getTokenType());
  default:
    LOG_ERR(__func__, "unary operators", m_lookahead.getTokenText());
  }

}

void Parser::assignment_operator()
{
  switch(m_lookahead.getTokenType()){
  case ASSIGN:                             /*TODO: other assignment operators, e.g. += -= *= /= */
    match(ASSIGN);
    return;
  default:
    LOG_ERR(__func__, "Assignment", m_lookahead.getTokenText());
  }

}


//expression
void Parser::primary_expression()
{
  switch(m_lookahead.getTokenType()){
  case IDENTIFIER: case CONSTANT: case LITERAL:
    match(m_lookahead.getTokenType());
    break;
  case L_PARENTHESIS:
    match(L_PARENTHESIS);
    primary_expression();
    match(R_PARENTHESIS);
    break;
  default:
    LOG_ERR(__func__, "identifier/constant/literal/(", m_lookahead.getTokenText());
  }
}

void Parser::postfix_expression()
{
  primary_expression();
  /*TODO*/
}

void Parser::unary_expression()
{
  postfix_expression();
  /*TODO others e.g. INC_OP unary_expression */

}

void Parser::cast_expression()
{

}

void Parser::multiplicative_expression()
{

}

void Parser::additive_expression()
{

}

void Parser::shift_expression()
{

}

void Parser::relational_expression()
{

}

void Parser::equality_expression()
{

}

void Parser::and_expression()
{

}

void Parser::exclusive_or_expression()
{

}

void Parser::inclusive_and_expresssion()
{

}

void Parser::logical_and_expression()
{

}

void Parser::logical_or_expression()
{

}

void Parser::conditional_expression()
{

}

void Parser::assignment_expression()
{
  /*TODO: conditional expression*/
  unary_expression();
  assignment_operator();
//  assignment_expression();
  arithmetic_expression();          /*TODO: temporary solution */
}

void Parser::expression()
{
  assignment_expression();
  /*TODO: multiple expressions*/
}

void Parser::arithmetic_expression()
{
  term();
  arithmetic_expression_left_recursion_eliminated();
  return ;
}

void Parser::arithmetic_expression_left_recursion_eliminated()
{
  switch(m_lookahead.getTokenType()){
  case PLUS: case MINUS:
    match(m_lookahead.getTokenType());
    term();
    arithmetic_expression_left_recursion_eliminated();
    return ;
  default:
    empty();
    return ;
  }
}

void Parser::term() {
  factor();
  term_left_recursion_eliminated();
}

void Parser::term_left_recursion_eliminated() {
  switch(m_lookahead.getTokenType()){
  case MUL: case DIV:
    match(m_lookahead.getTokenType());
    factor();
    term_left_recursion_eliminated();
    return ;
  default:
    empty();
    return;
  }
}

void Parser::factor() {
  switch(m_lookahead.getTokenType()){
  case L_PARENTHESIS:
    match(L_PARENTHESIS);
    arithmetic_expression();
    match(R_PARENTHESIS);
    return ;
  case CONSTANT:
    match(CONSTANT);
    return ;
  default:
    LOG_ERR(__func__, "( or constant", m_lookahead.getTokenText());
  }
}

void Parser::empty() {
  return ;
}


//block
void Parser::block_item()
{

}

void Parser::block_item_list()
{

}

//function
void Parser::function_definition()
{

}

void Parser::function_declaration()
{

}


//helper functions
void Parser::match(TokenType x)
{
  if(x == m_lookahead.getTokenType()) {
    eat();
  }
  //todo
  else{
    LOG_ERR(__func__, x, m_lookahead.getTokenText());
  }
}

void Parser::eat() {
  m_lookahead = m_lexer.nextToken();
}
