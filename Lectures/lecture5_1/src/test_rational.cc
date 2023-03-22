/* Copyright 2020
 */


#include <test_rational.h>

using std::cout;
using std::endl;
using std::istream;
using std::stringstream;
using std::string;
using std::ostream;


int main(int argc, char* argv[]) {
  Rational expected, lhs, rhs;

  cout << "FUNCTION TestRationalAdd" << endl;
  expected = Rational(19, 24), lhs = Rational(2, 3), rhs = Rational(1, 8);
  cout << "  Positive + Positive: "
    << (TestRationalAdd(expected, lhs, rhs) ? "PASSED" : "FAILED")
    << endl;
  expected = Rational(-13, 24), lhs = Rational(-2, 3), rhs = Rational(1, 8);
  cout << "  Negative + Positive: "
    << (TestRationalAdd(expected, lhs, rhs) ? "PASSED" : "FAILED")
    << endl;
  expected = Rational(-19, 24), lhs = Rational(-2, 3), rhs = Rational(-1, 8);
  cout << "  Negative + Negative: "
    << (TestRationalAdd(expected, lhs, rhs) ? "PASSED" : "FAILED")
    << endl;

  cout << "FUNCTION TestRationalInsert" << endl;
  expected = Rational(7, 8);
  stringstream sin = stringstream("7/8");
  expected = Rational(7, 8);
  cout << "  Positive: "
    << (TestRationalInsert(expected, &sin) ? "PASSED" : "FAILED")
    << endl;
  expected = Rational(-7, 8);
  sin = stringstream("-7/8");
  cout << "  Negative: "
    << (TestRationalInsert(expected, &sin) ? "PASSED" : "FAILED")
    << endl;

  cout << "FUNCTION TestRationalExtract" << endl;
  Rational input(3, 4);
  std::string expected_str = "3/4";
  cout << "  Positive: "
    << (TestRationalExtract(input, expected_str) ? "PASSED" : "FAILED")
    << endl;
  input = Rational(-3, 4);
  expected_str = "-3/4";
  cout << "  Negative: "
    << (TestRationalExtract(input, expected_str) ? "PASSED" : "FAILED")
    << endl;
  input = Rational(3, 21);
  expected_str = "1/7";
  cout << "  Simplified: "
    << (TestRationalExtract(input, expected_str) ? "PASSED" : "FAILED")
    << endl;

  return 0;
}


bool TestRationalAdd(const Rational& expected,
                     const Rational& lhs,
                     const Rational& rhs) {
  Rational actual = lhs.Add(rhs);
  return expected.num() == actual.num() && expected.den() == actual.den();
}


bool TestRationalInsert(const Rational& expected, istream* from) {
  Rational actual;
  actual.Insert(from);
  return expected.num() == actual.num() && expected.den() == actual.den();
}


bool TestRationalExtract(const Rational& input, const string& expected) {
  stringstream sout;
  input.Extract(&sout);
  return expected == sout.str();
}
