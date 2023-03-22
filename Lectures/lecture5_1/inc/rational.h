/* Copyright 2020 CSCE 240
 *
 * Class
 *  This library introduces classes. It provides a rational class which will
 *  serve as the basis for future lectures describing programming class topics
 *  as well as C++ class topics.
 */


#include <istream>
#include <ostream>

/* Rational
 *  Stores the numerator (num) and denominator (den) as a pair of unsigned
 *  integers. It uses a boolean to manage positive/negative-ness and is
 *  efficienct in deciding when to reduce---only when displaying or comparing.
 *
 *   + Rational() : Rational
 *   + Rational(int, int) : Rational
 *   + den() : int
 *   + num() : int
 *   + Add(const Rational&) : const Rational
 *   + Extract(ostream*) : ostream*
 *   + Insert(istream*) : istream*
 *
 *   - GCD(int, int) : int
 *   - num : int
 *   - den : int
 *   - positive : bool
 */
class Rational;
  // basic initialization constructor and default constructor

  // inline accessors

  /* Add: calculates and returns the sum of the calling instance and the
   * parameter without changing either.
   */

  /* Extract: extracts the contents of calling instance and appends to ostream
   * parameter. Parameter will be changed, calling instance will not. Returns
   * the parameter for chaining.
   */

  /* Insert: extracts a pair of integers separated by a slash from the
   * parameter and stores in the calling instance, modifying both. Returns the
   * parameter for chaining.
   */
