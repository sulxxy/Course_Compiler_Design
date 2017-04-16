#include "utils.h"

void LOG_ERR(string err_src, string expected, string got)
{
  throw  runtime_error("ERR: " + err_src + ": expected " + expected + ", got " + got);
}

void LOG_DBG(string dbg_src, string content)
{
  std::cout << "DBG: " <<  dbg_src << ": " << content << std::endl;
}

void LOG_ERR(string err_src, int expected, string got)
{
  throw  runtime_error("ERR: " + err_src + ": expected " + std::to_string(expected) + ", got " + got);

}
