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

bool TestAddAndGetGrade();


int main(int argc, char* argv[]) {
  int passed = 0;

  std::cout << "Testing GradeBook::Add(char) and GradeBook::Get(size_t)"
      << std::endl;
  if (TestAddAndGetGrade())
    std::cout << "  PASSED" << std::endl;
  else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }

  return passed;
}


bool TestAddAndGetGrade() {
  bool passed = true;

  for (size_t i = 0; i < kBooks; ++i) {
    GradeBook actual;
    for (size_t j = 0; j < kSize; ++j)
      actual.Add(kGrades[i][j]);

    for (size_t j = 0; j < kSize; ++j)
      if (kGrades[i][j] != actual.Get(j)) {
        std::cout << "  Expected Grade at " << j << ": " << kGrades[i][j]
            << ", Actual: " << actual.Get(j) << std::endl;
        passed = false;
      }
  }

  GradeBook actual;
  if (actual.Get(0)!= '\0') {
    std::cout << "  Expected Grade at " << 0 << ": \\0"
        << ", Actual: " << actual.Get(0) << std::endl;
    passed = false;
  }
  
  return passed;
}
