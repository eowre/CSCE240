/* Copyright 2020 CSCE 240
 */
#include <problem4.h>
#include <problem4.h>  // test correct header constuction

#include <cstddef>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  if (kTestVal != 'B')  // test correct header construction
    return 255;

  const unsigned int kValues[] = { 3, 5, 13, 21, 69, 201 };
  const std::string kExpected[] = {
    "11", "101", "1101", "10101", "1000101", "11001001" };
  for (size_t i = 0; i < sizeof(kValues)/sizeof(int); ++i) {
    std::cout << "DecimalToBinary(" << kValues[i] << ")" << std::endl;
    std::cout << " Expected: " << kExpected[i] << ", Actual: "
      << DecimalToBinary(kValues[i]) << std::endl;
  }
  return 0;
}
