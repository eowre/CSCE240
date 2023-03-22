#include <cmath>
#include <iostream>


#include <inc/gradebook.h>


const size_t kBooks = 3;
const size_t kSize = 3;
const double kGrades[kBooks][kSize] = {
  { 'B', 'A', 'A' },
  { 'C', 'B', 'A' },
  { 'C', 'A', 'A' }
};


bool TestAddGradeBook();


int main(int argc, char* argv[]) {
  int passed = 0;

  std::cout << "Testing GradeBook::AddGradeBook(const GradeBook&)" << std::endl;
  if (TestAddGradeBook())
    std::cout << "  PASSED" << std::endl;
  else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }
  

  return passed;
}


bool TestAddGradeBook() {
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

    actual = actual.Add(tmp);
  }

  for (size_t i = 0; i < kBooks*kSize; ++i) {
    if (actual.Get(i) != expected[i]) {
      std::cout << "  Expected Grade at " << i << ": " << expected[i]
          << ", Actual: " << actual.Get(i) << std::endl;
      passed = false;
    }
  }

  return passed;
}
