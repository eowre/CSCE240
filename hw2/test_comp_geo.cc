/* Copyright 2020 CSCE 240
 */
#include <cmath>
// using fabs
// using fmin
#include <iostream>
using std::cout;
using std::endl;
#include <limits>
using std::numeric_limits;


#include <comp_geo.h>
#include <comp_geo.h>  // did you guard your define with defining guards?


bool TestCalcCircumference();
bool TestCalcCircleArea();
bool TestCalcPerimeter();
bool TestCalcRectangleArea();
bool TestCalcDistanceSquared();
bool TestCalcDistance();
bool TestPointsEqual();

int main(int argc, char* argv[]) {
  const int k_idx = 1;  // test number parameter index
  int test = argc == 2 ? atoi(argv[k_idx]) : -1;

  switch (test) {
  case 0:
    cout << "TestCalcCircumference" << endl;
    if (TestCalcCircumference()) {
      cout << "  PASSED" << endl;
      return 0;
    } else {
      cout << "  FAILED" << endl;
      return 1;
    }

  case 1:
    cout << "TestCalcCircleArea" << endl;
    if (TestCalcCircleArea()) {
      cout << "  PASSED" << endl;
      return 0;
    } else {
      cout << "  FAILED" << endl;
      return 1;
    }

  case 2:
    cout << "TestCalcPerimeter" << endl;
    if (TestCalcPerimeter()) {
      cout << "  PASSED" << endl;
      return 0;
    } else {
      cout << "  FAILED" << endl;
      return 1;
    }

  case 3:
    cout << "TestRectangleArea" << endl;
    if (TestCalcRectangleArea()) {
      cout << "  PASSED" << endl;
      return 0;
    } else {
      cout << "  FAILED" << endl;
      return 1;
    }

  case 4:
    cout << "TestCalcDistanceSquared" << endl;
    if (TestCalcDistanceSquared()) {
      cout << "  PASSED" << endl;
      return 0;
    } else {
      cout << "  FAILED" << endl;
      return 1;
    }

  case 5:
    cout << "TestCalcDistance" << endl;
    if (TestCalcDistance()) {
      cout << "  PASSED" << endl;
      return 0;
    } else {
      cout << "  FAILED" << endl;
      return 1;
    }

  case 6:
    cout << "TestPointsEqual" << endl;
    if (TestPointsEqual()) {
      cout << "  PASSED" << endl;
      return 0;
    } else {
      cout << "  FAILED" << endl;
      return 1;
    }

  default:
    cout << "Compiled and executed" << endl;
  }

  return 0;
}

bool fpeq(double a, double b, double epsilon = 0.000001);

bool TestCalcCircumference() {
  const double expected = 41.861174448;
  double actual = CalcCircumference(-1.25, 6.67, -2.5, 0.1259);

  if (!fpeq(expected, actual)) {
    cout << "  Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}

bool TestCalcCircleArea() {
  const double expected = 139.448213005;
  double actual = CalcCircleArea(-2.5, 0.1259, -1.25, 6.67);

  if (!fpeq(expected, actual)) {
    cout << "  Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}

bool TestCalcPerimeter() {
  const double expected = 9.44426;
  double actual = CalcPerimeter(0.00887, -1.0001, 2.731, 0.9999);

  if (!fpeq(expected, actual)) {
    cout << "  Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}

bool TestCalcRectangleArea() {
  const double expected = 5.44426;
  double actual = CalcRectangleArea(2.731, 0.9999, 0.00887, -1.0001);

  if (!fpeq(expected, actual)) {
    cout << "  Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}

bool TestCalcDistanceSquared() {
  const double expected = 0.011750732;
  double actual = CalcDistanceSquared(-0.021, -0.014, 0.00215, 0.0919);

  if (!fpeq(expected, actual)) {
    cout << "  Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}

bool TestCalcDistance() {
  const double expected = 0.001949938;
  const double alt_expected = 0.012251819;
  double actual = CalcDistance(0.0, 0.0, 0.0009371, -0.00171);

  if (fpeq(expected, actual) || fpeq(alt_expected, actual)) {
    return true;
  } else {
    cout << "  Neither" << endl;
    cout << "\tExpected: " << expected << ", Actual: " << actual << endl;
    cout << "  or" << endl;
    cout << "\tExpected: " << alt_expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}

bool TestPointsEqual() {
  const double x_1 = 1.0/10.0, y_1 = 3.0/10.0,
    x_2 = 0.05 + 0.05, y_2 = 0.1 + 0.1 + 0.1;

  return PointsEqual(x_1, y_1, x_2, y_2);
}

bool fpeq(double a, double b, double epsilon) {
  if (a == b)  // trivially true
    return true;

  double abs_a = fabs(a);
  double abs_b = fabs(b);
  double diff = fabs(a - b);

  if (a == 0 || b == 0 || (abs_a + abs_b < numeric_limits<double>::min())) {
    // when a or b is zero or both are extremely close to zero
    // relative error is less meaningful
    return diff < (epsilon * numeric_limits<double>::min());
  } else {  // use relative error
    return diff / fmin((abs_a + abs_b), numeric_limits<double>::max())
        < epsilon;
  }
}
