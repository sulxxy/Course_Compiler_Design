#ifndef PARSER_H
#define PARSER_H

#include "scanner.h"

class Parser
{
public:
  Parser(const Scanner&);
  void primary_statement();
  void expression();
  void print_expression();
  void match(TokenType);
  void eat();
private:
  Scanner m_lexer;
  Token m_lookahead;

};

#endif // PARSER_H
