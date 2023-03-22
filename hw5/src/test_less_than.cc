/* Copyright 2020 CSCE240
 */
#include <inc/gradebook.h>

#include <cmath>
#include <iostream>


const size_t kBooks = 3;
const size_t kSize = 3;
const char kGrades[kBooks][kSize] = {
  { 'B', 'D', 'D' },
  { 'C', 'B', 'A' },
  { 'D', 'F', 'A' }
};


bool TestLessThanOp();


int main(int argc, char* argv[]) {
  int passed = 0;

  std::cout << "Testing GradeBook::operator<(const GradeBook&)" << std::endl;
  if (TestLessThanOp()) {
    std::cout << "  PASSED" << std::endl;
  } else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }

  return passed;
}


bool TestLessThanOp() {
  bool passed = true;

  GradeBook books[3];
  for (size_t i = 0; i < kBooks; ++i)
    for (size_t j = 0; j < kSize; ++j)
      books[i].Add(kGrades[i][j]);

  if (books[1] < books[0]) {  // TEST less than op
    std::cout << "  Expected ";
    for (size_t k = 0; k < kSize; ++k)
      std::cout << books[1][k] << " ";  // TEST bracket op
    std::cout << "< ";

    for (size_t k = 0; k < kSize; ++k) {
      std::cout << books[0][k];  // TEST bracket op
      if (k < kSize - 1)
        std::cout << " ";
    }
    std::cout << ": True, Actual: False" << std::endl;

    passed = false;
  }

  if (books[2] < books[0]) {  // TEST less than op
    std::cout << "  Expected ";
    for (size_t k = 0; k < kSize; ++k)
      std::cout << books[2][k] << " ";  // TEST bracket op
    std::cout << "< ";

    for (size_t k = 0; k < kSize; ++k) {
      std::cout << books[0][k];  // TEST bracket op
      if (k < kSize - 1)
        std::cout << " ";
    }
    std::cout << ": True, Actual: False" << std::endl;

    passed = false;
  }

  return passed;
}
