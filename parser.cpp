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
      LOG_ERR("type_specifier", m_lookahead.getTokenText());
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



//expression
void Parser::expression()
{
}

void Parser::arithmetic_expression() {
  term();
  arithmetic_expression_left_recursion_eliminated();
}

void Parser::arithmetic_expression_left_recursion_eliminated() {
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
  recursion();
  term_left_recursion_eliminated();
}

void Parser::term_left_recursion_eliminated() {
  switch(m_lookahead.getTokenType()){
  case MUL: case DIV:
    match(m_lookahead.getTokenType());
    recursion();
    term_left_recursion_eliminated();
    return ;
  default:
    empty();
    return;
  }
}

void Parser::recursion() {
  switch(m_lookahead.getTokenType()){
  case L_PARENTHESIS:
    match(L_PARENTHESIS);
    arithmetic_expression();
    match(R_PARENTHESIS);
    return ;
  case NUMBER:
    match(NUMBER);
    return ;
  default:
    throw runtime_error("Expected ( or a digit, got <" + m_lookahead.getTokenText() + "> \n");
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
    LOG_ERR(x, m_lookahead.getTokenText());
  }
}

void Parser::eat() {
  m_lookahead = m_lexer.nextToken();
}
