#include "scanner.h"

Scanner::Scanner(string input) : m_input(input)
{
  m_current_index = 0;
  m_current_char = m_input.at(m_current_index);

}

Scanner::Scanner(const Scanner& src)
{
  m_current_char = src.getCurrentChar();
  m_current_index = src.getCurrentIndex();
  m_input = src.getInput();
}

Token Scanner::nextToken()
{
  while(m_current_char != EOF ){
    switch(m_current_char) {
    case ' ': case '\t': case '\n': case '\r':
      skipWS();
      break;
      //return Token(WS, "White Space");
    case ',':
      eat();
      return Token(COMMA, ",");
    case ':':
      eat();
      return Token(COLON, ":");
    case ';':
      eat();
      return Token(SEMICOLON, ";");

    case '+':
      eat();
      return Token(PLUS, "+");
    case '-':
      eat();
      return Token(MINUS, "-");
    case '*':
      eat();
      return Token(MUL, "*");
    case '/':
      eat();
      return Token(DIV, "/");
    case '<':
      eat();
      if(m_current_char == '=') {
        eat();
        return Token(LE, "<=");
      }else{
        return Token(LT, "<");
      }
    case '>':
      eat();
      if(m_current_char == '=') {
        return Token(GE, ">=");
      }else{
        return Token(GT, ">");
      }
    case '=':
      eat();
      if(m_current_char == '=') {
        eat();
        return Token(EQ, "==");
      }else{
        return Token(ASSIGN, "=");
      }
    case '!':
      eat();
      if(m_current_char == '=') {
        eat();
        return Token(NE, "!=");
      }else{
        return Token(RESERVE, "TODO LATER");
      }

    case '(':
      eat();
      return Token(L_PARENTHESIS, "(");
    case ')':
      eat();
      return Token(R_PARENTHESIS, ")");
    case '[':
      eat();
      return Token(L_BRACKET, "[");
    case ']':
      eat();
      return Token(R_BRACKET, "]");
    case '{':
      eat();
      return Token(L_BRACE, "{");
    case '}':
      eat();
      return Token(R_BRACE, "}");

    case EOF:
      return Token(EOF_TYPE, "<EOF>");

    default:
      if(isalpha(m_current_char) || m_current_char == '_') {
        return matchKeyword();
      }
      else if(isdigit(m_current_char)) {
        return matchDigit();
      }
      else{
        return Token(RESERVE, "TODO LATER");
      }
    }
  }
  return Token(EOF_TYPE, "<EOF>");

}

char Scanner::getCurrentChar() const
{
  return m_current_char;

}

int Scanner::getCurrentIndex() const
{
  return m_current_index;
}

string Scanner::getInput() const
{
  return m_input;
}

void Scanner::eat()
{
  m_current_index++;
  if(m_current_index >= m_input.length()) {
    m_current_char = EOF;
    return ;
  }
  m_current_char = m_input.at(m_current_index);
}

void Scanner::match(char x)
{
  if(m_current_char == x) eat();
  else throw std::runtime_error("Expect " + string(1, x) + ", but got " + string(1, m_current_char));
}

Token Scanner::matchKeyword(){
        stringstream buf;
        do {
          buf << m_current_char;
          eat();
        } while(isalpha(m_current_char) || isdigit(m_current_char) || m_current_char == '_');
        string s = buf.str();
        if( s == "bool"){
          return Token(BOOL, s);
        }
        else if (s == "char") {
          return Token(CHAR, s);
        }
        else if (s == "short") {
          return Token(SHORT, s);
        }
        else if (s == "void") {
          return Token(VOID, s);
        }
        else if (s == "int") {
          return Token(INT, s);
        }
        else if (s == "float") {
          return Token(FLOAT, s);
        }
        else if (s == "double") {
          return Token(DOUBLE, s);
        }
        else if (s == "unsigned") {
          return Token(UNSIGNED, s);
        }
        else if (s == "long") {
          return Token(LONG, s);
        }
        else if (s == "if") {
          return Token(IF, s);
        }
        else if (s == "else") {
          return Token(ELSE, s);
        }
        else if (s == "when") {
          return Token(WHEN, s);
        }
        else if (s == "do") {
          return Token(DO, s);
        }
        else if (s == "while") {
          return Token(WHILE, s);
        }
        else if (s == "break") {
          return Token(BREAK, s);
        }
        else if (s == "switch") {
          return Token(SWITCH, s);
        }
        else if (s == "case") {
          return Token(CASE, s);
        }
        else if (s == "continue") {
          return Token(CONTINUE, s);
        }
        else if (s == "struct") {
          return Token(STRUCT, s);
        }
        else if (s == "enum") {
          return Token(ENUM, s);
        }
        else if (s == "extern") {
          return Token(EXTERN, s);
        }
        else if (s == "inline") {
          return Token(INLINE, s);
        }
        else if (s == "return") {
          return Token(RETURN, s);
        }
        else{
          return Token(IDENTIFIER, s);
        }

}

Token Scanner::matchDigit() {
        stringstream buf;
        do {
          buf << m_current_char;
          eat();
        } while(isdigit(m_current_char) ); /* todo: support float point */
        int scanned_value = stoi(buf.str());
        return Token(CONSTANT, buf.str(), scanned_value);
}

void Scanner::skipWS() {
  while(m_current_char == ' ' || m_current_char == '\t' || m_current_char == '\n' || m_current_char == '\r') {
    eat();
  }
}

void Scanner::unitTest() {
  while(m_current_char != EOF){
    cout << nextToken() << endl;
  }
}
