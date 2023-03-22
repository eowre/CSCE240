/* Copyright 2020
 */


#include <test_person.h>

using std::cout;
using std::endl;
using std::stringstream;
using std::string;


int main(int argc, char* argv[]) {
  const size_t kSize = 2;
  Person *expected = new Person[kSize];
  expected[0] = ConstructPerson("Brianna", "Zhang", ConstructDate(2002, 3, 21));
  expected[1] = ConstructPerson(
    "Michael", "Johnson", ConstructDate(2000, 10, 31));

  stringstream *ssin = new stringstream;
  *ssin << "Brianna Zhang 2002 3 21 ";
  *ssin << "Michael Johnson 2000 10 31";
  cout << "FUNCTION TestPersonInsert: "
    << (TestPersonInsert(expected, kSize, ssin) ? "PASSED" : "FAILED")
    << endl;
  delete ssin;

  cout << "FUNCTION TestPersonEquals: "
    << (TestPersonEquals(expected, kSize) ? "PASSED" : "FAILED") << endl;

  delete [] expected;
  return 0;
}


bool TestPersonInsert(const Person* expected,
                      size_t size,
                      std::istream* input) {
  Person *actual = new Person[size];
  for (size_t i = 0; i < size; ++i)
    Insert(input, (actual + i));

  for (size_t i = 0; i < size; ++i)
    if (expected[i].first_name != actual[i].first_name
        || expected[i].last_name != actual[i].last_name
        || expected[i].date_of_birth.year != actual[i].date_of_birth.year
        || expected[i].date_of_birth.month != actual[i].date_of_birth.month
        || expected[i].date_of_birth.day != actual[i].date_of_birth.day) {
      return false;
      delete [] actual;
    }

  return true;
  delete [] actual;
}


bool TestPersonEquals(const Person* test_values, size_t size) {
  for (size_t i = 0; i < size; ++i)
    if (!Equals(test_values[i], test_values[i]))
      return false;

  for (size_t i = 0, j = size - 1; i < size; ++i, --j)
    if (Equals(test_values[i], test_values[j]))
      return false;

  return true;
}
