
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;

#include <inc/median.h>
using csce240::Median;
#include <inc/statistic.h>
using csce240::Statistic;

bool TestMedianCalculate(Statistic*);

int main(int argc, char* argv[]) {
  Statistic *stat = new Median();
  cout << "Testing Median::Calculate()" << endl;
  if (!TestMedianCalculate(stat)) {
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

const double kData[] = {17, 17.5, 27.224, 34.34, 81.9, 91.17, 101.0};

bool TestMedianCalculate(Statistic* stat) {
  const double kData[] = {17.5, 27.224, 91.17, 101.0, 34.34, 81.9};
  const unsigned int kSize = sizeof(kData) / sizeof(double);

  for (unsigned int i = 0; i < kSize; ++i)
    stat->Collect(kData[i]);

  double expected = 58.12;
  double actual = stat->Calculate();
  if (!FPEq(expected, actual)) {
    cout << "  Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  stat->Collect(17); 

  expected = 34.34;
  actual = stat->Calculate();
  if (expected != actual) {
    cout << "  Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}
