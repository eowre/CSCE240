/* Copyright 2020 CSCE 240
 */
#include <problem5.h>
#include <problem5.h>  // test correct header constuction

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  if (kTestVal != 'C')  // test correct header construction
    return 255;

  const std::string kFileName = "integers.txt";
  const int kExpected = 42;
  std::cout << "LargestInteger(" << kFileName << ")" << std::endl;
  std::cout << " Expected: " << kExpected << ", Actual: "
      << LargestInteger(kFileName) << std::endl;
  return 0;
}
