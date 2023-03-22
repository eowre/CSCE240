/* Copyright 2020 Evan Owre
 * DecimalToBinary
 *  Accepts an unsigned integer value and returns the binary representation of
 *  that number. For example, 3 returns the string "11", 5 returns the string
 *  "101", and 17 returns "10001".
 *
 *  A simple algorithm you might use is as follows:
 *   (1) Begin with an empty string.
 *   (2) Divide decimal value by 2. If there is a remainder, add a "0" to the
 *       beginning of the string or a "1" if not.
 *   (3) Reduce the decimal value by half, taking its floor, i.e.
 *       floor(5 / 2) = 2. Note this is the behavior of integer arithmetic.
 *   (4) Repeat steps 2 and 3 until the decimal value is 0.
 *
 * References:
 *  string: http://cplusplus.com/reference/string/
 *
 * Points:
 *  -compilation: 1
 *  -style: 2
 *  -correctness: 2
 */

#ifndef PROBLEM4_H_
#define PROBLEM4_H_
#include <string>


std::string DecimalToBinary(unsigned int decimal_value);

const char kTestVal = 'B';  // used to test correct header construction
#endif  // PROBLEM4_H_
