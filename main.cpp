#include "mainwindow.h"
#include "symboltable.h"
#include "scanner.h"
#include "parser.h"

#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  /*
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
  */


  string s = "a=2;";
  Scanner st(s);
//  st.unitTest();
  Parser pt(st);
//  pt.declaration();
//  pt.arithmetic_expression();
  pt.expression_statement();
  return 0;
}
