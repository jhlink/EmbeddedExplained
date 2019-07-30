#include "leap.h"

bool is_leap_year(const int year) {
  bool divisible_by_four = year % 4 == 0;
  bool ignore_centuries = year % 100 == 0;
  return ignore_centuries ? false : divisible_by_four;
}
