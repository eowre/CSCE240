/* Copyright 2020 Evan Owre
 */
#include <problem3.h>

#include <iostream>
using std::cout;
using std::endl;
#include <cmath>
// using pow
// using log
#include <cstddef>
int SumDigits(int value) {
  int check = 0;
  if (value < 0) {
    ++check;
    value = value * -1;
  }
  int size = (1+log10(value));
  int out = 0;
  for (int i = size; i > 0; --i) {
    int exp = pow(10, i-1);  // calculates power of 10
    int base = (value/exp)%10;  // calculstes base
    out = out + base;
  }
  if (check == 1)
    out = out * -1;
  return out;
}
