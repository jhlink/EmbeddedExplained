#include "grains.h"

ULL_INT square(const int square_index) {
  bool is_invalid = !square_index || square_index > 64;
  ULL_INT result = is_invalid ? 0ull : 1ull << (square_index - 1); 
  return result;
}

ULL_INT total() {
  ULL_INT sum = 0ull;
  for (int i = 0; i < 65; i++) {
    sum += square(i); 
  }
  return sum;
}
