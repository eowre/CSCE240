/* Copyright 2020 */

#include <iostream>


void HelloWorld01(void);
void HelloWorld02(void);


int main(int argc, char* argv[]) {
  // call HelloWorld01
  HelloWorld01();

  // call HelloWorld02
  HelloWorld02();

  return 0;
}


/* A void function which displays Hello, World named HelloWorld01
 */
void HelloWorld01(void) {
  std::cout << "Hello, World" << std::endl;
}


/* A void function which displays Hello, World named HelloWorld02
 */
void HelloWorld02(void) {
  std::cout << "Hello, World" << std::endl;
}
