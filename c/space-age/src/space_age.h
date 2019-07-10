#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#include <stdbool.h>
#include <math.h>

#define SECONDS_PER_DAY 86400
#define DAYS_ON_EARTH 365.25

#define EARTH 1
#define MERCURY 0.2408467
#define VENUS 0.61519726
#define MARS 1.8808158
#define JUPITER 11.862615
#define SATURN 29.447498
#define URANUS 84.016846
#define NEPTUNE 164.79132

float convert_planet_age(float planet_time, unsigned long age);

#endif
