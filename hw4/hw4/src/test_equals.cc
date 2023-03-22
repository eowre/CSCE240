#include <cmath>
#include <iostream>


#include <inc/gradebook.h>


const size_t kBooks = 3;
const size_t kSize = 3;
const char kGrades[kBooks][kSize] = {
  { 'B', 'A', 'A' },
  { 'C', 'B', 'A' },
  { 'C', 'A', 'A' }
};
const char kGPAs[kBooks] = { 'A', 'B', 'B' };
const char kMaxes[kBooks] = { 'A', 'A', 'A' };


bool TestEquals();


int main(int argc, char* argv[]) {
  int passed = 0;

  std::cout << "Testing GradeBook::Equals(const GradeBook&)" << std::endl;
  if (TestEquals())
    std::cout << "  PASSED" << std::endl;
  else {
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

  if (!actuals[1].Equals(actuals[2])) {
    std::cout << "  Expected ";
    for (size_t k = 0; k < kSize; ++k)
      std::cout << kGrades[1][k] << " ";
    std::cout << "== ";

    for (size_t k = 0; k < kSize; ++k) {
      std::cout << actuals[2].Get(k);
      if (k < kSize - 1)
        std::cout << " ";
    }
    std::cout << ": False, Actual: True" << std::endl;

    passed = false;
  }

  if (actuals[0].Equals(actuals[1])) {
    std::cout << "  Expected ";
    for (size_t k = 0; k < kSize; ++k)
      std::cout << kGrades[0][k] << " ";
    std::cout << "== ";

    for (size_t k = 0; k < kSize; ++k) {
      std::cout << actuals[1].Get(k);
      if (k < kSize - 1)
        std::cout << " ";
    }
    std::cout << ": True, Actual: False" << std::endl;

    passed = false;
  }

  return passed;
}
