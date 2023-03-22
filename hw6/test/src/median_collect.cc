
#include <iostream>
using std::cout;
using std::endl;

#include <inc/median.h>
using csce240::Median;
#include <inc/statistic.h>
using csce240::Statistic;

void TestMedianCollect(Statistic*);

int main(int argc, char* argv[]) {
  Statistic *stat = new Median();
  TestMedianCollect(stat);
  cout << "Testing Median::Collect(double)" << endl;
  cout << "  PASSED" << endl;
  delete stat;
  

  return 0;
}


void TestMedianCollect(Statistic* stat) {
  const double kData[] = {17.5, 27.224, 91.17, 101.0, 34.34, 81.9};
  const unsigned int kSize = sizeof(kData) / sizeof(double);

  for (unsigned int i = 0; i < kSize; ++i)
    stat->Collect(kData[i]);
}
