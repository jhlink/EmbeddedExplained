#include "leap.h"

bool is_leap_year(const int year) {
  bool divisible_by_4 = year % 4 == 0;
  bool ignore_centuries = year % 100 == 0;
  bool divisible_by_400 = year % 400 == 0; 

  return ignore_centuries ? divisible_by_400 : divisible_by_4;
}
