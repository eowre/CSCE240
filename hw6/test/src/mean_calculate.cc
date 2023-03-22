/* Copyright 2020 CSCE240
 */
#include <inc/mean.h>
using csce240::Mean;
#include <inc/statistic.h>
using csce240::Statistic;

#include <cmath>
#include <cstddef>
// using size_t
#include <iostream>
using std::cout;
using std::endl;


bool TestMeanCalculate(Statistic*);

int main(int argc, char* argv[]) {
  Statistic *stat = new Mean();
  cout << "Testing Mean::Calculate()" << endl;
  if (!TestMeanCalculate(stat)) {
    cout << "  FAILED" << endl;
    return 1;
  }
  cout << "  PASSED" << endl;
  delete stat;
  return 0;
}

bool FPEq(double lhs, double rhs) {
  const double kABS_diff = 0.00001;
  return fabs(lhs - rhs) < kABS_diff;
}

bool TestMeanCalculate(Statistic* stat) {
  const double kData[] = {17.5, 27.224, 91.17, 101.0, 34.34, 81.9};
  const unsigned int kSize = sizeof(kData) / sizeof(double);

  double expected = 0.0;
  for (const double* d_itr = kData; d_itr != kData + kSize; ++d_itr)
    expected += *d_itr;
  expected /= kSize;

  for (unsigned int i = 0; i < kSize; ++i)
    stat->Collect(kData[i]);

  double actual = stat->Calculate();
  if (!FPEq(expected, actual)) {
    cout << "  Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}
