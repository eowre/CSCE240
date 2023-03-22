// Copyright 2020 Evan Owre
#include <inc/time_span.h>
#include <istream>
#include <ostream>
using std::istream;
using std::ostream;
const int sixty = 60;
TimeSpan::TimeSpan() : hours_(0), min_(0), sec_(0) { /* empty */ }

TimeSpan::TimeSpan(int hours, int minutes, int seconds)
  : hours_(hours), min_(minutes), sec_(seconds) {
  while (sec_ >= sixty) {
    sec_ = sec_ - sixty;
    ++min_;
  }
  while (min_ >= sixty) {
    min_ = min_ - sixty;
    ++hours_;
  }
}

int TimeSpan::hours() const { return hours_; }

int TimeSpan::minutes() const { return min_; }

int TimeSpan::seconds() const { return sec_; }

const TimeSpan TimeSpan::Add(const TimeSpan& rhs) const {
  int ret_sec = sec_ + rhs.sec_;
  int adj = 0;
  while (ret_sec >= sixty) {
    ret_sec = ret_sec - sixty;
    ++adj;
  }
  int ret_min = min_ + rhs.min_ + adj;
  adj = 0;
  while (ret_min >= sixty) {
    ret_min = ret_min - sixty;
    ++adj;
  }
  int ret_hours = hours_ + rhs.hours_ +adj;
  return TimeSpan(ret_hours, ret_min, ret_sec);
}

const TimeSpan TimeSpan::operator+(const TimeSpan& rhs) const {
  return Add(rhs);
}

const TimeSpan operator+(int lhs, const TimeSpan& rhs) {
  TimeSpan seconds(0, 0, lhs);
  return rhs.Add(seconds);
}

istream& TimeSpan::Insert(istream* in) {
  char temp1, temp2;
  *in >> hours_ >> temp1 >> min_ >> temp2 >> sec_;
  return *in;
}
ostream& TimeSpan::Extract(ostream* out) const {
  *out << hours_ << " : " << min_ << " : " << sec_;
  return *out;
}
std::istream& operator>>(std::istream& lhs, TimeSpan& rhs) {
  return rhs.Insert(&lhs);
}

std::ostream& operator<<(std::ostream& lhs, const TimeSpan& rhs) {
  return rhs.Extract(&lhs);
}
