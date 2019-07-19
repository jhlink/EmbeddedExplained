#include "grains.h"

unsigned long long square(const unsigned long square_index) {
  unsigned long long result = 1 << (square_index - 1); 
  return result;
}

unsigned long long total() {
  return 0ull;
}
