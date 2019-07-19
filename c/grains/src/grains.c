#include "grains.h"

unsigned long long square(const int square_index) {
  bool is_invalid = !square_index || square_index > 64;
  unsigned long long result = is_invalid ? 0ull : 1ull << (square_index - 1); 
  return result;
}

unsigned long long total() {
  return 0ull;
}
