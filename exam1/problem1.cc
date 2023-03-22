/*  COpyright 2020 Evan Owre
 *  Problem1: prefix notation arithmetic calculator
 *  Arithmetic is customarily represented using infix notation, e.g. 1.0 + 2.0.
 *  In this assignment, you are creating a prefix notation calculator,
 *  e.g. + 1.0 2.0.
 *
 *  The program will read the operator and operands from the standard input
 *  stream (using cin). The operator will be first and the left-hand side and
 *  right-hand side operands will be second and third, respectively. You will
 *  then write the output of the operation to the standard output stream (using
 *  cout).
 *
 *  DO NOT emit anything other than the result. This is a calculator. Simply
 *  emit the result of the operation. Do not prompt for input. Just write the
 *  result of the operation.
 *
 *  You must provide operators:
 *    + : addition
 *    - : subtraction
 *    x : multiplication
 *    / : division
 *    < : less than
 *    > : greater than
 *
 * Notes:
 *  The two operands should be read as floating point data and the operator is a
 *  character. You need not set precision for the floating point
 *  output. The default precision for a double is all that is required.
 *
 * Points:
 *  compilation: 1
 *  style: 1
 *  correctness: 3
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  char ops[] = "+-x/<>";
  char op;
  double val1;
  double val2;
  cin >> op;;
  cin >> val1;
  cin >> val2;
  if (op == ops[4]) {
    if (val1 < val2) {
      cout << "true" << endl;
    } else {
      cout << "false";
    }
  }
  if (op == ops[5]) {
    if (val1 > val2) {
      cout << "true" << endl;
    } else {
      cout << "false";
    }
  }
  if (op == ops[0]) {
    double ret = val1 + val2;
    cout << ret << endl;
  }
  if (op == ops[1]) {
    double ret = val1 - val2;
    cout << ret << endl;
  }
  if (op == ops[2]) {
    double ret = val1*val2;
    cout << ret << endl;
  }
  if (op == ops[3]) {
    double ret = val1/val2;
    cout << ret << endl;
  }
}
