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


//  string s = "    sdf bool rt";
//  Scanner st(s);
//  st.unitTest();
  cout << isdigit('c') << endl;
  cout << isdigit('1') << endl;
  //Parser pt(st);
  //pt.print_expression();
  return 0;
}
