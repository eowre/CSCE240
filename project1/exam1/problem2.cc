/*  Copyright 2020 Evan OWre
 *  Problem2: prefix notation arithmetic calculator
 *  Arithmetic is customarily represented using infix notation, e.g. 1 + 2. In
 *  this assignment, you are creating a prefix notation calculator, e.g. + 1 2.
 *
 *  Read the three arguments passed into the file. They will be at indices 1,
 *  2, and 3. The operator will be at index 1, the left and right operands at
 *  indices 2 and 3, respectively. You will then write the output of the
 *  operation. DO NOT emit anything else. This is a calculator. Simply write the
 *  result of the operation to the standard output stream (using cout).
 *
 *  You must provide operators:
 *    + : addition
 *    - : subtraction
 *    x : multiplication
 *    / : division
 *    % : modulo
 *    ^ : exponentiation
 *
 * Notes:
 *  The two operands should be converted to integral data and the operator is a
 *  character. The arguments are passed in as character arrays (char* argv[])
 *  and so the operator cannot be directly compared to string literals such as
 *  "+". I would recommend using the string class, which accepts a character
 *  array in its constructor and provides the == (equivalency) operator to
 *  determine which operator was provided.
 *
 *  The operands can be converted from character arrays (char* argv[]) to
 *  signed ints by the atoi function.
 *
 * References:
 *  atoi: cplusplus.com/reference/cstdlib/atoi/
 *  string: http://www.cplusplus.com/reference/string/
 *
 * Points:
 *  compilation: 1
 *  style: 1
 *  correctness: 3
 */
#include <iostream>
using std::cout;
using std::endl;
#include <cstdlib>
// using atoi;
#include <cstddef>
// using size_t
#include <cmath>


int main(int agrc, char* argv[]) {
  const size_t kOp_idx = 1;
  const size_t kVal1_idx = 2;
  const size_t kVal2_idx = 3;
  char op = argv[kOp_idx][0];
  //  note this magic number specifies
  //  the char* argv array is holding a char
  double val1 = atoi(argv[kVal1_idx]);
  double val2 = atoi(argv[kVal2_idx]);
  char ops[] = "+-x/%^";  //  array of possible operators
  //  cout << op << " " << val1 << " " << val2 << endl;
  if (op == ops[4]) {
    double temp = val1;
    double ret;
    while (temp > 0) {
      if ((temp - val2) < val2) {
        ret = temp - val2;
        temp = 0;
      } else if ((temp - val2) == 0) {
          ret = temp = 0;
      } else {
          temp = temp - val2;
      }
    }
    cout << ret << endl;
  }
  if (op == ops[5]) {
    double ret = pow(val1, val2);
    cout << ret << endl;
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
