#include "space_age.h"

static bool float_equality(float a, float b, float tolerance) {
  return fabs(a - b) < tolerance;
}

float convert_planet_age(float planet_time, unsigned long age) {
  float result = 0;
  if ( float_equality( planet_time, EARTH, .01 ) ) {
    result = age / planet_time; 
  } else { 
    float planet_yr_sec_ratio = EARTH * planet_time;
    result = age / planet_yr_sec_ratio;
  }
  return result;
}
