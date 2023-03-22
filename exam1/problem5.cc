/* Copyright 2020 Evan Owre
 */
#include <problem5.h>
#include <fstream>
using std::fstream;
//  using std::getline; from orginal line counter

int LargestInteger(const std::string& file_name) {
  int num_of_lines;  // ints for number of lines and temp for finding largest
  int temp;
  fstream myfile(file_name);  // using fstream object to open file
  // while (getline(myfile, line)) first attempt to count lines
    // ++n;
  myfile >> num_of_lines;  // using iostream inheritence to grab number of lines
  int ret = 0;  // return value
  for (int i = 0; i < num_of_lines; ++i) {  // for loop for
          // simple sortig algorithm
    myfile >> temp;  //  stores first value to compare
            // against the return value, not ret starts at 0
    if (temp > ret)  // if temp is larger than the ret value,
            // ret is updated to the larger value.
      ret = temp;
  }
  return ret;  // returns largest value
}
