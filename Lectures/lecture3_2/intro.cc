/* Copyright 2020
 *
 * Separate functions into declaration and definition to fix scope issue.
 */

#include <iostream>


/* A void function which displays Hello, World named HelloWorld01
 */
void HelloWorld01(void) {
  // comments describe to a maintainer the functionality
  std::cout << "Hello, World" << std::endl;
}

/* A void function which displays Hello, World named HelloWorld02
 */
void HelloWorld02(void) {
  std::cout << "Hello, World" << std::endl;
}


int main(int argc, char* argv[]) {
  // call HelloWorld01
  HelloWorld01();

  // call HelloWorld02
  HelloWorld02();

  return 0;
}
