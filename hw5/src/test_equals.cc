/* Copyright 2020 CSCE240
 */
#include <inc/gradebook.h>

#include <cmath>
#include <iostream>


const size_t kBooks = 3;
const size_t kSize = 3;
const char kGrades[kBooks][kSize] = {
  { 'B', 'A', 'A' },
  { 'C', 'B', 'A' },
  { 'C', 'A', 'A' }
};


bool TestEquals();


int main(int argc, char* argv[]) {
  int passed = 0;

  std::cout << "Testing GradeBook::operator==(const GradeBook&)" << std::endl;
  if (TestEquals()) {
    std::cout << "  PASSED" << std::endl;
  } else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }

  return passed;
}


bool TestEquals() {
  bool passed = true;
  GradeBook actuals[3];

  for (size_t i = 0; i < kBooks; ++i)
    for (size_t j = 0; j < kSize; ++j)
      actuals[i].Add(kGrades[i][j]);

  if (actuals[1] != actuals[2]) {  // TEST not equal op
    std::cout << "  Expected ";
    for (size_t k = 0; k < kSize; ++k)
      std::cout << kGrades[1][k] << " ";
    std::cout << "!= ";

    for (size_t k = 0; k < kSize; ++k) {
      std::cout << actuals[2][k];  // TEST bracket op
      if (k < kSize - 1)
        std::cout << " ";
    }
    std::cout << ": True, Actual: False" << std::endl;

    passed = false;
  }

  if (actuals[0] == actuals[1]) {  // TEST equals OP
    std::cout << "  Expected ";
    for (size_t k = 0; k < kSize; ++k)
      std::cout << kGrades[0][k] << " ";
    std::cout << "== ";

    for (size_t k = 0; k < kSize; ++k) {
      std::cout << actuals[1][k];
      if (k < kSize - 1)
        std::cout << " ";
    }
    std::cout << ": True, Actual: False" << std::endl;

    passed = false;
  }

  return passed;
}
