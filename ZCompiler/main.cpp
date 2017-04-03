#include "mainwindow.h"
#include "symboltable.h"
#include <QApplication>
#include <iostream>
#include <scanner.h>

using namespace std;

int main(int argc, char *argv[])
{
  /*
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
  */


  string s = ",.";
  Scanner st(s);
  Token t = st.nextToken();
  while(t.getTokenType() != EOF_TYPE){
    cout << t.toString() << endl;
    t = st.nextToken();
  }
  return 0;
}
