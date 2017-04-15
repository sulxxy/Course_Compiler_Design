#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include "token.h"
#include "utils.h"

using namespace std;

class Scanner
{
public:
  //Scanner(File);
  Scanner(string);
  Scanner(const Scanner&);
  Token nextToken();
  char getCurrentChar() const;
  int getCurrentIndex() const;
  string getInput() const;
  void eat();
  void match(char x);
  Token matchKeyword();
  Token matchDigit();
  void skipWS();
  void unitTest();

private:
  string m_input;
  char m_current_char;
  int m_current_index;
};

#endif // SCANNER_H
