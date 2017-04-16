#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>

using namespace std;


void LOG_ERR(string err_src, string expected, string err_content);
void LOG_ERR(string err_src, int expected, string err_type);
void LOG_DBG(string dbg_src, string content);
/*todo
void LOG_INFO(string);
*/

#endif // UTILS_H
