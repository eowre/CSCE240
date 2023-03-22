/* Copyright 2020 CSCE240
 */
#include <inc/gradebook.h>

#include <cmath>
#include <iostream>


const size_t kBooks = 3;
const size_t kSize = 3;
const double kGrades[kBooks][kSize] = {
  { 'B', 'A', 'A' },
  { 'C', 'B', 'A' },
  { 'C', 'A', 'A' }
};


bool TestPlusOp();


int main(int argc, char* argv[]) {
  int passed = 0;

  std::cout << "Testing GradeBook::operator[](const GradeBook&)" << std::endl;
  if (TestPlusOp()) {
    std::cout << "  PASSED" << std::endl;
  } else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }

  return passed;
}


bool TestPlusOp() {
  bool passed = true;

  double expected[kBooks*kSize];
  for (size_t i = 0; i < kBooks; ++i)
    for (size_t j = 0; j < kSize; ++j)
      expected[i*kBooks + j] = kGrades[i][j];

  GradeBook actual;
  for (size_t i = 0; i < kBooks; ++i) {
    GradeBook tmp;
    for (size_t j = 0; j < kSize; ++j)
      tmp.Add(kGrades[i][j]);

    actual = actual + tmp;  // TEST plus op
  }

  for (size_t i = 0; i < kBooks*kSize; ++i) {
    if (actual[i] != expected[i]) {  // bracket op
      std::cout << "  Expected Grade at " << i << ": " << expected[i]
          << ", Actual: " << actual[i] << std::endl;  // bracket op
      passed = false;
    }
  }

  return passed;
}
