// TimeSpan Points:
// Compiles: 1 (make test_time_span)
// Lints: 1  (cpplint --root=./ */time_span.*)
// TestPlusTimeSpan: 1
// TestPlusInt: 1
// TestPlusExtract: 1
// TestPlusInsert: 1
// Copyright 2020 Evan Owre

#ifndef INC_TIME_SPAN_H_
#define INC_TIME_SPAN_H_
#include <istream>
#include <ostream>


/* A measurement of time, representable as a number of hours minutes and
 * seconds.
 *
 *  You must supply the provided portions of the public interface without
 *  change. You may add other useful methods, as you require.
 */
class TimeSpan {
 private:
    // class memebers
    int hours_;
    int min_;
    int sec_;

 public:
  // represents no time
  TimeSpan();

  // represents a span covering the parameters
  TimeSpan(int hours, int minutes, int seconds);

  // these must be provided for any test to pass
  int hours() const;  // returns the whole hours in the span
  int minutes() const;  // returns the whole minutes in the span
  int seconds() const;  // returns the seconds in the span

  // returns sum of two TimeSpans
  const TimeSpan Add(const TimeSpan& that) const;

  // returns the sum of two TimeSpan instances
  const TimeSpan operator+(const TimeSpan& rhs) const;

  // insert method for operator overload
  std::istream& Insert(std::istream* in);

  // Extract method for operator overload
  std::ostream& Extract(std::ostream* out) const;
};

// returns the sum of a number of seconds as an int and a TimeSpan
const TimeSpan operator+(int lhs, const TimeSpan& rhs);

// extracts the TimeSpan as HH : MM : SS
std::istream& operator>>(std::istream& lhs, TimeSpan& rhs);

// inserts the TimeSpan from HH : MM : SS each being formatted as an int
std::ostream& operator<<(std::ostream& lhs, const TimeSpan& rhs);

#endif  // INC_TIME_SPAN_H_
