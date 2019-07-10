#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#include <stdbool.h>
#include <math.h>

//  Equivalent to 365.25 Earth Days
#define EARTH 31557600

//  Subsequent planet values are in Earth Years
#define MERCURY 0.2408467
#define VENUS 0.61519726
#define MARS 1.8808158
#define JUPITER 11.862615
#define SATURN 29.447498
#define URANUS 84.016846
#define NEPTUNE 164.79132

float convert_planet_age(float planet_time, unsigned long age);

#endif
