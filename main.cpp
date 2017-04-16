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


  string s = "long a,b,c;";
  Scanner st(s);
//  st.unitTest();
  Parser pt(st);
  pt.declaration();
  return 0;
}
