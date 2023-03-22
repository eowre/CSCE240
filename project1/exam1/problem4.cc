/* Copyright 2020 Evan Owre
 */
#include <problem4.h>
#include <string>
// using append
#include <cmath>
// using pow and log
#include <iostream>
using std::cout;
using std::endl;
std::string DecimalToBinary(unsigned int decimal_value) {
  std::string binary;
  int working_val = decimal_value;
  while (working_val > 0) {
    int test = working_val/2;
    if ((working_val%2)+test == test)
      binary = "0"+binary;
    else
      binary = "1"+binary;
    working_val = working_val/2;
  }
  return binary;
}
