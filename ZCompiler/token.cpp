#include "token.h"

Token::Token(TokenType type, string text) : m_tokenType(type), m_text(text)
{

}

TokenType Token::getTokenType(){
  return m_tokenType;
}

string Token::toString()
{
  stringstream s;
  s << "<" << m_text << ", " << m_tokenType << ">" ;
  return s.str();
}
