/* Copyright 2020 */
#ifndef LECTURE5_1_INC_TEST_RATIONAL_H_
#define LECTURE5_1_INC_TEST_RATIONAL_H_


#include <rational.h>

#include <cassert>
// using assert
#include <cstddef>
// using size_t

#include <iostream>
#include <istream>
#include <sstream>
#include <string>


bool TestRationalAdd(const Rational& expected,
                     const Rational& lhs,
                     const Rational& rhs);


bool TestRationalInsert(const Rational& expected, std::istream* from);


bool TestRationalExtract(const Rational& input, const std::string& expected);

#endif  // LECTURE5_1_INC_TEST_RATIONAL_H_
