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


  string s ="int a; int b=3;";
  Scanner st(s);
//  st.unitTest();
  Parser pt(st);
//  pt.declaration();
//  pt.arithmetic_expression();
  pt.declaration_list();
  return 0;
}
