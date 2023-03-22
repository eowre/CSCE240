// Copyright 2020 Evan Owre
#include <inc/functional_array.h>
#include <cstddef>
// using size_t
size_t** Allocate(const size_t* sizes, size_t length) {
  size_t **ret = new size_t*[length];
  for (size_t i = 0; i < length; ++i)
    ret[i] = new size_t[sizes[i]];
  for (size_t i = 0; i < length; ++i)
    for (size_t j = 0; j < sizes[i]; ++j)
      ret[i][j] = sizes[i];
  return ret;
}
size_t Deallocate(const size_t** arrays, const size_t* sizes, size_t length) {
  size_t ret = 0;
  for (size_t i = 0; i < length; ++i) {
    ret = ret + (sizes[i]*sizes[i]);
    delete[] arrays[i];
  }
  delete[] arrays;
  return ret;
}
