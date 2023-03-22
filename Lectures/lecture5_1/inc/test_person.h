/* Copyright 2020 */
#ifndef LECTURE5_1_INC_TEST_PERSON_H_
#define LECTURE5_1_INC_TEST_PERSON_H_


#include <person.h>

#include <cassert>
// using assert
#include <cstddef>
// using size_t

#include <iostream>
#include <istream>
#include <sstream>
#include <string>


bool TestPersonInsert(const Person* expected, size_t size, std::istream* input);
bool TestPersonEquals(const Person* test_values, size_t size);


#endif  // LECTURE5_1_INC_TEST_PERSON_H_
