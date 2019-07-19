#include "grains.h"

unsigned long long square(const unsigned long square_index) {
  unsigned long long result = square_index ? 1ull << (square_index - 1) : 0ull; 
  return result;
}

unsigned long long total() {
  return 0ull;
}
