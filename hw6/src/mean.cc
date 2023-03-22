/* Copyright 2020 Evan Owre
 */
#include <inc/mean.h>
#include <inc/statistic.h>
#include <vector>
#include <cstddef>
#include <iostream>
using std::cout;
using std::endl;
// using size_t
using std::vector;
using csce240::Mean;
using csce240::Statistic;
Mean::Mean() {
  nums_.push_back(0);
  size_ = 0;
}

Mean::~Mean() {/* empty */}

void Mean::Collect(double datum) {
  if (size_ == 0) {
    nums_[0] = datum;
    ++size_;
  } else {
    nums_.push_back(datum);
    ++size_;
  }
}
double Mean::Calculate() const {
  double ret;
  double total = 0;
  for (size_t i = 0; i < size_; ++i) {
    total = total + nums_[i];
  }
  ret = total/size_;
  return ret;
}
