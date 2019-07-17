#ifndef NUCLEO_COUNT_H
#define NUCLEO_COUNT_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NUCLEO_COUNT_STRING_TEMPLATE "A:%i C:%i G:%i T:%i"

typedef struct NUCLEO_COUNT {
  int A;
  int C;
  int G;
  int T;
} nucleo_count;


char* count(const char dna_strand[]);

#endif
