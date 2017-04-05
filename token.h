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
  Token(const Token&);
//  string toString();
  TokenType getTokenType() const;
  string getTokenText() const;
  friend ostream& operator <<(ostream&, const Token&);
private:
  TokenType m_tokenType;
  string m_text;
};

#endif // TOKEN_H
