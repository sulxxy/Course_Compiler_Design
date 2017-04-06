#include "token.h"

Token::Token()
{
  m_tokenType = STARTING_TYPE;
  m_text = "";
}

Token::Token(TokenType type, string text, int value) : m_tokenType(type), m_text(text), m_value(value)
{

}

Token::Token(const Token& t){
  m_tokenType = t.getTokenType();
  m_text = t.getTokenText();
}

TokenType Token::getTokenType() const
{
  return m_tokenType;
}

string Token::getTokenText() const
{
  return m_text;
}

//string Token::toString()
//{
//  stringstream s;
//  s << "<" << m_text << ", " << m_tokenType << ">" ;
//  return s.str();
//}

ostream& operator <<(ostream& out, const Token& t){
  out << "<" << t.getTokenType() << "  " << t.getTokenText() << ">";
  return out;
}
