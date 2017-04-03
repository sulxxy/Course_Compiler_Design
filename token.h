#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <sstream>

#include "symboltable.h"

using namespace std;

class Token
{
public:
  Token();
  Token(TokenType type, string text);
  string toString();
  TokenType getTokenType();
private:
  TokenType m_tokenType;
  string m_text;
};

#endif // TOKEN_H
