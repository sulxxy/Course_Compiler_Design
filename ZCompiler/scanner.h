#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include "token.h"

using namespace std;


class Scanner
{
public:
  //Scanner(File);
  Scanner(string);
  Token nextToken();
  void eat();

private:
  string m_input;
  char m_current_char;
  int m_current_index;
};

#endif // SCANNER_H
