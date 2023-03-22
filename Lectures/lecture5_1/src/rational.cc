/* Copyright 2020 CSCE 240
 */

/* GCD: uses Euclids subtraction method to calculate the greatest common
 * divisor of the two parameters without changing the calling instance.
 * Returns the GCD.
 */
int GCD(int a, int b) {
  while (a != b)
    if (a > b)
      a -= b;
    else
      b -= a;
  return a;
}
