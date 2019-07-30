#include "leap.h"

bool is_leap_year(const int year) {
  bool is_divisible_by_4 = year % 4 == 0;
  bool is_century = year % 100 == 0;
  bool is_divisible_by_400 = year % 400 == 0; 

  return is_century ? is_divisible_by_400 : is_divisible_by_4;
}
