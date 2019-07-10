#include "space_age.h"

float convert_planet_age(float planet_time, unsigned long age) {
  float earth_yr_in_sec = SECONDS_PER_DAY * DAYS_ON_EARTH;
  return age / ( planet_time * earth_yr_in_sec );
}
