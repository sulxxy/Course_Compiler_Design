#include "parser.h"

Parser::Parser(const Scanner& s) : m_lexer(s)
{
  m_lookahead = m_lexer.nextToken();
}

void Parser::primary_statement()
{
}

void Parser::expression()
{
}

void Parser::print_expression()
{
//  match(PRINT);
  return ;
}

void Parser::match(TokenType x)
{
  if(x == m_lookahead.getTokenType()) {
    eat();
  }
  //todo
  else throw std::runtime_error("Expect type is not same with received type");
}

void Parser::eat() {
  m_lookahead = m_lexer.nextToken();
}
