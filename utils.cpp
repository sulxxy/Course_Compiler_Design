#include "utils.h"

void LOG_ERR(string expected, string got)
{
  throw  runtime_error("expected " + expected + ", got " + got);
}

void LOG_DBG(string function_name, string content)
{
  std::cout << "DBG: " << function_name << ": " << content << std::endl;
}

void LOG_ERR(int expected, string got)
{
  throw  runtime_error("expected " + std::to_string(expected) + ", got " + got);

}
