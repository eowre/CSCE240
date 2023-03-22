/* Copyright 2020 CSCE240
 */


/* Tests the functions.
 */
int main(int argc, char* argv[]) {
  // Test Swap
  int x = 10, y = 12;
  Swap(x, y);
  if (y < x)
    std::cout << "Swap: PASSED" << std::endl;
  else
    std::cout << "Swap: FAILED" << std::endl;
  
  // Test DblQuoteString
  std::string expected = "\"Hello, World\"";
  std::string actual = DblQuoteString("Hello, World");
  if (expected == actual)
    std::cout << "DblQuoteString: PASSED" << std::endl;
  else
    std::cout << "DblQuoteString: FAILED"
      << " Expected: " << expected
      << ", Actual: " << actual << std::endl;
  
  // Test SngQuoteString
  expected = "'Hello, World'";
  actual = SngQuoteString("Hello, World");
  if (expected == actual)
    std::cout << "SngQuoteString: PASSED" << std::endl;
  else
    std::cout << "SngQuoteString: FAILED"
      << " Expected: " << expected
      << ", Actual: " << actual << std::endl;
  
  return 0;
}
