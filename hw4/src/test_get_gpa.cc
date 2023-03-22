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


bool TestGetGPA();


int main(int argc, char* argv[]) {
  int passed = 0;

  std::cout << "Testing GradeBook::GetGPA()" << std::endl;
  if (TestGetGPA())
    std::cout << "  PASSED" << std::endl;
  else {
    std::cout << "  FAILED" << std::endl;
    passed = 1;
  }

  return passed;
}


bool TestGetGPA() {
  bool passed = true;
  GradeBook actuals[3];

  for (size_t i = 0; i < kBooks; ++i)
    for (size_t j = 0; j < kSize; ++j)
      actuals[i].Add(kGrades[i][j]);

  for (size_t i = 0; i < kBooks; ++i)
    if (kGPAs[i] != actuals[i].GetGPA()) {
      std::cout << "  Expected GPA at " << i << ": " << kGPAs[i]
          << ", Actual: " << actuals[i].GetGPA() << std::endl;
      passed = false;
    }

  return passed;
}
