/* Copyright 2020 Evan Owre
 */
#include <inc/median.h>
#include <inc/statistic.h>
#include <vector>
#include <cstddef>
// using size_t
using std::vector;
using csce240::Median;
using csce240::Statistic;

vector<double> Sort(vector<double> nums, size_t size);

Median::Median() {
  nums_.push_back(0);
  size_ = 0;
}

Median::~Median() {/* empty */}

void Median::Collect(double datum) {
  if (size_ == 0) {
    nums_[0] = datum;
    ++size_;
  } else {
    nums_.push_back(datum);
    ++size_;
  }
}
double Median::Calculate() const {
  double ret;
  vector<double> sorted = Sort(nums_, size_);
  if (size_%2 == 0) {
    ret = (sorted[(size_/2)-1]+sorted[size_/2])/2;
  } else {
    ret = sorted[size_/2];
  }
  return ret;
}

vector<double> Sort(vector<double> nums, size_t size) {
  size_t i, j;
  bool swap;
  for (i = 0; i < size - 1; ++i) {
    swap = false;
    for (j = 0; j < size - i - 1; ++j) {
      if (nums[j] > nums[j+1]) {
        double temp = nums[j];
        nums[j] = nums[j+1];
        nums[j+1] = temp;
        swap = true;
      }
    }
    if (swap == false)
      break;
  }
  return nums;
}
