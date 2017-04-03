#include "scanner.h"

Scanner::Scanner(string input) : m_input(input)
{
  m_current_index = 0;
  m_current_char = m_input.at(m_current_index);

}

Token Scanner::nextToken()
{
  while(m_current_char != EOF ){
    switch(m_current_char) {
    case ',':
      eat();
      return Token(COMMA, string(1, ','));
    default:
      return Token(EOF_TYPE, "<EOF>");
    }
  }

}

void Scanner::eat()
{
  m_current_index++;
  m_current_char = m_input.at(m_current_index);

}
