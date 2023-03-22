// Copyright 2020 Evan Owre
#include <inc/sum_finder.h>
#include <cstddef>  // using size_t
void count(int sum,
           const int** matrix,
           const size_t matrix_size[],
           size_t* sums_found);
size_t** FindSum(int sum,
                 const int** matrix,
                 const size_t matrix_size[],
                 size_t* sums_found) {
  count(sum, matrix, matrix_size, sums_found); // counts number of sums
  const size_t kRows = matrix_size[kRow];  // constants for later math
  const size_t kCols = matrix_size[kCol];
  size_t **ret = new size_t*[*sums_found];
  for (size_t i = 0; i < *sums_found; ++i)
    ret[i] = new size_t[4];  // building the 2D array
  size_t store_row = 0; // used to track which row to use
  for (size_t i = 0; i < kRows; ++i)  // algorithim to find the proper sums
    for (size_t j = 0; j < kCols; ++j) {  // then store them into the 2D array
      int test_val = matrix[i][j];
      if (test_val == sum) {
        ret[store_row][kStartRow] = i;
        ret[store_row][kStartCol] = j;
        ret[store_row][kEndRow] = i;
        ret[store_row][kEndCol] = j;
        ++store_row;
      }
      for (size_t l = j+1; l < kCols; ++l) {
        test_val = test_val + matrix[i][l];
        if (test_val ==sum) {
          ret[store_row][kStartRow] = i;
          ret[store_row][kStartCol] = j;
          ret[store_row][kEndRow] = i;
          ret[store_row][kEndCol] = l;
          ++store_row;
        }
      }
    }
  for (size_t i = 0; i < kRows; ++i)  // same algorithim as above rotated to 
    for (size_t j = 0; j < kCols; ++j) {  // look through columns for sums
      int test_val = matrix[j][i];
      if (test_val == sum) {
        ret[store_row][kStartRow] = j;
        ret[store_row][kStartCol] = i;
        ret[store_row][kEndRow] = j;
        ret[store_row][kEndCol] = i;
        ++store_row;
      }
      for (size_t l = j+1; l < kRows; ++l) {
        test_val = test_val + matrix[l][i];
        if (test_val == sum) {
          ret[store_row][kStartRow] = j;
          ret[store_row][kStartCol] = i;
          ret[store_row][kEndRow] = l;
          ret[store_row][kEndCol] = i;
          ++store_row;
        }
      }
    }
  return ret;
}
void count(int sum,
           const int** matrix,
           const size_t matrix_size[],
           size_t* sums_found) {
  const size_t kRows = matrix_size[kRow];  // creating constants to work with
  const size_t kCols = matrix_size[kCol];  // implements same searching algorithm
  *sums_found = *sums_found +1;  // updates sums_found to equal 0 initially
  for (size_t i = 0; i < kRows; ++i)
    for (size_t j = 0; j < kCols; ++j) {
      int test_val = matrix[i][j];
      if (test_val == sum)
        *sums_found = *sums_found + 1;
      for (size_t l = j+1; l < kCols; ++l) {
        test_val = test_val + matrix[i][l];
        if (test_val == sum) {
          *sums_found = *sums_found + 1;
        }
      }
    }
  for (size_t i = 0; i < kCols; ++i)
    for (size_t j = 0; j < kRows; ++j) {
      int test_val = matrix[j][i];
      if (test_val == sum)
        *sums_found = *sums_found + 1;
      for (size_t l = j+1; l < kRows; ++l) {
        test_val = test_val + matrix[l][i];
        if (test_val == sum)
          *sums_found = *sums_found + 1;
      }
    }
}
