/* Copyright 2020 Evan Owre
 * LargestInteger
 *  The function accepts a string file name, opens the file, reads the
 *  contents, and returns the largest value found inside (excluding the count
 *  of integers).
 *
 *  The file format consists of an integer n, followed by n additional positive
 *  and negative integers. The values are all separated by white space and so
 *  can be parsed using the insertion operator (>>). You should probably use
 *  the fstream object (which accepts a string in its constructor) to read the
 *  integers.
 *
 * References:
 *  fstream: http://cplusplus.com/reference/fstream/
 *  string: http://cplusplus.com/reference/string/
 *
 * Points:
 *  -compilation: 1
 *  -style: 2
 *  -correctness: 2
 */

#ifndef PROBLEM5_H_
#define PROBLEM5_H_
#include <string>


int LargestInteger(const std::string& file_name);

const char kTestVal = 'C';  // used to test correct header construction
#endif  // PROBLEM5_H_
