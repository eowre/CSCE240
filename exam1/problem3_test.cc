/* Copyright 2020 CSCE 240
 */
#include <problem3.h>
#include <problem3.h>  // check correct header construction

#include <cstddef>  // size_t
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  if (kTestVal != 'A')  // check correct header construction
    return -1;

  int values[] = { 8154, -7613 };
  int expected[] = { 18, -17 };
  for (size_t i = 0; i < sizeof(values)/sizeof(int); ++i) {
    cout << "SumDigits(" << values[i] << ")" << endl;
    cout << " Expected: " << expected[i] << ", Actual: "
      << SumDigits(values[i]) << endl;
  }
  return 0;
}
