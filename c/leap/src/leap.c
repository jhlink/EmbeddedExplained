#include "leap.h"

bool is_leap_year(const int year) {
  bool divisible_by_four = year % 4 == 0;
  return divisible_by_four;
}
