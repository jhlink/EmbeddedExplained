#include "acronym.h"

size_t count_delims(const char *src, const char *delim) {
  size_t result = 0;
  int index = 0;
  while ( src[index] != '\0' ) {
    if ( src[index] == *delim ) result++;
    index++;
  }

  return result;
}

char* abbreviate(const char *phrase) {
  char* result = NULL; 

  if ( phrase ) {

  }

  return result;
}
