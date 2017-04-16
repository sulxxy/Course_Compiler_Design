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
  Token(TokenType type, string text, int value=0);
  Token(const Token&);
//  string toString();
  TokenType getTokenType() const;
  string getTokenText() const;
  friend ostream& operator <<(ostream&, const Token&);
  int getTokenValue() const;
private:
  TokenType m_tokenType;
  string m_text;
  int m_value;      //TODO value type to be changed
};

#endif // TOKEN_H
