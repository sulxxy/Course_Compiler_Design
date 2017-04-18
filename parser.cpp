#include "parser.h"


//constructor
Parser::Parser(const Scanner& s) : m_lexer(s)
{
  m_lookahead = m_lexer.nextToken();
}


//statements
void Parser::primary_statement()
{
  switch(m_lookahead.getTokenType()){
  case CASE:case DEFAULT:
    labeled_statement();
    return ;
  case L_BRACE:
    compound_statement();
    return;
  case IDENTIFIER: case CONSTANT: case LITERAL:
    expression_statement();
    return;
  case IF:case SWITCH:
    selection_statement();
    return;
  case FOR:case DO: case WHILE:
    iteration_statement();
    return;
  default:
    LOG_ERR(__func__, "compound/iteration/selection statement", "unsupported statement");
    return;
  }
}

void Parser::labeled_statement()
{

}

void Parser::compound_statement()
{
  match(L_BRACE);
  if(m_lookahead.getTokenType() == R_BRACE){
    match(R_BRACE);
  }
  else{
    block_item_list();
    match(R_BRACE);
  }
  LOG_DBG(__func__, "GOT a compound statement");

}

void Parser::selection_statement()
{
  if(m_lookahead.getTokenType() == IF){
    match(IF);
    match(L_PARENTHESIS);
    expression();
    match(R_PARENTHESIS);
    primary_statement();
    if(m_lookahead.getTokenType() == ELSE){
      match(ELSE);
      primary_statement();
    }
  }
  else if(m_lookahead.getTokenType() == SWITCH){
    match(SWITCH);
    match(L_PARENTHESIS);
    expression();
    match(R_PARENTHESIS);
    primary_statement();
  }
  LOG_DBG(__func__, "GOT a selection statement");
  return;
}

void Parser::iteration_statement()
{
  switch(m_lookahead.getTokenType()){
  case WHILE:
    match(WHILE);
    match(L_PARENTHESIS);
    expression();
    match(R_PARENTHESIS);
    primary_statement();
    break;
  case DO:
    match(DO);
    primary_statement();
    match(WHILE);
    match(L_PARENTHESIS);
    expression();
    match(R_PARENTHESIS);
    match(SEMICOLON);
    break;
  case FOR:
    match(FOR);
    match(L_PARENTHESIS);
    /* form: for(a=5;b=6;c=7) */
    expression_statement();
    expression_statement();
    expression();
    match(R_PARENTHESIS);
    primary_statement();
    /* todo: other forms, e.g. for(a=6;b=6;); for(int a=6;b=6;c=7); for(int a= 6; b=6;); */
    break;
  }
  LOG_DBG(__func__, "GOT a iteration statement");

}

void Parser::jump_statement()
{

}

void Parser::expression_statement()
{
  if(m_lookahead.getTokenType() == SEMICOLON){
    match(SEMICOLON);
  }
  else{
    expression();
    match(SEMICOLON);
  }
  LOG_DBG(__func__, "GOT an expression statement");
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
    LOG_DBG(__func__, "GOT a declaration");      //e.g. int ();
    return;
  }
  else{
    init_declarator_list();
    match(SEMICOLON);
    LOG_DBG(__func__, "GOT a declaration");     //e.g. int a;
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
  if(m_lookahead.getTokenType() == ASSIGN){
    match(ASSIGN);
    initializer();
  }
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
  }
  else if(m_lookahead.getTokenType() == L_PARENTHESIS){
    match(L_PARENTHESIS);
    declarator();
    match(R_PARENTHESIS);
  }
  direct_declarator_left_recursion_eliminated();
    /*TODO*/
}

void Parser::direct_declarator_left_recursion_eliminated()
{
  switch(m_lookahead.getTokenType()){
  case L_PARENTHESIS:
    match(L_PARENTHESIS);
    if(is_declaration_type(m_lookahead.getTokenType())){
      parameter_type_list();
    }
    else if(m_lookahead.getTokenType() == IDENTIFIER){
      identifier_list();
    }
    match(R_PARENTHESIS);
    direct_declarator_left_recursion_eliminated();
    break;
  case L_BRACKET:
    match(L_BRACKET);
    LOG_ERR(__func__, "[", "types or productions that currently not supported");
    direct_declarator_left_recursion_eliminated();
    break;
  default:
    break;
  }
  return ;
}

void Parser::declaration_list()
{
  declaration();
  declaration_list_left_recursion_eliminated();
}

void Parser::declaration_list_left_recursion_eliminated()
{
  switch(m_lookahead.getTokenType()){
  case VOID: case BOOL: case CHAR: case SHORT: case INT: case LONG: case FLOAT: case DOUBLE:
    declaration();
    declaration_list_left_recursion_eliminated();
    break;
  default:
    empty();
    break;
  }
}

void Parser::external_declaration()
{
  function_definition();
  /*TODO: add declaration*/
}

void Parser::parameter_type_list()
{
  parameter_list();
  /*TODO */
}

void Parser::parameter_list()
{
  parameter_declaration();
  parameter_list_left_recursion_eliminated();
}

void Parser::parameter_list_left_recursion_eliminated()
{
  if(m_lookahead.getTokenType() == COMMA){
    match(COMMA);
    parameter_declaration();
    parameter_list_left_recursion_eliminated();
  }
  else{
    empty();
  }
  return;
}

void Parser::parameter_declaration()
{
  declaration_specifiers();
  if(is_declaration_type(m_lookahead.getTokenType())){
    declarator();
    /*TODO: abstract declarator */
  }
  return ;
}

void Parser::identifier_list()
{
  match(IDENTIFIER);
  identifier_list_left_recursion_eliminated();

}

void Parser::identifier_list_left_recursion_eliminated()
{
  if(m_lookahead.getTokenType() == COMMA){
    match(COMMA);
    match(IDENTIFIER);
    identifier_list_left_recursion_eliminated();
  }
  else{
    empty();
  }
  return ;
}

void Parser::translation_unit()
{
  external_declaration();
  translation_unit_left_recursion_eliminated();
}

void Parser::translation_unit_left_recursion_eliminated()
{
  if(is_declaration_type(m_lookahead.getTokenType())){
    external_declaration();
    translation_unit_left_recursion_eliminated();
  }
  else{
    empty();
  }
  return ;

}

void Parser::initializer()
{
//  assignment_expression();
  arithmetic_expression();
  /*TODO: initializer_list */
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
    expression();
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
  switch(m_lookahead.getTokenType()){
  case INT:case BOOL:case CHAR:case VOID:case LONG:case SHORT:case FLOAT:case DOUBLE:   /*todo: other types, or write some functions to do this kind of thing */
    declaration();
    return ;
  default:                  /*todo: there maybe other cases here */
    primary_statement();
    return;
  }

}

void Parser::block_item_list()
{
  block_item();
  block_item_list_left_recursion_eliminated();
}

void Parser::block_item_list_left_recursion_eliminated()
{
  switch(m_lookahead.getTokenType()){
  case INT:case BOOL:case CHAR:case VOID:case LONG:case SHORT:case FLOAT:case DOUBLE:case FOR:case WHILE: case DO: case IF:case SWITCH: case IDENTIFIER: case CONSTANT:  /*todo: modify later */
    block_item();
    block_item_list_left_recursion_eliminated();
    return;
  default:
    empty();
    return;
  }
}

//function
void Parser::function_definition()
{
  declaration_specifiers();
  declarator();
  if(m_lookahead.getTokenType() == L_BRACE){
    compound_statement();
  }
  else{
    declaration_list();
    compound_statement();
  }
  LOG_DBG(__func__, "GOT a function definition" );
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

bool Parser::is_declaration_type(TokenType t)
{
  switch(t)
  {
  case VOID: case BOOL: case CHAR: case SHORT: case INT: case LONG: case FLOAT: case DOUBLE:
    return true;
  default:
    return false;
  }
}
