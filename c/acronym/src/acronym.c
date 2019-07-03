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

  if ( phrase && strlen(phrase) > 0) {
    // Two is added for the starting letter and null termination
    size_t acronym_size = count_delims(phrase, " ") + 2;
    size_t phrase_len = strlen(phrase);

    result = (char*) malloc(sizeof(char) * acronym_size);

    assert(result != NULL);

    int acronym_index = 0;
    result[acronym_index++] = phrase[0];
    result[acronym_size - 1] = '\0';

    for ( size_t i = 0; i < phrase_len - 1; i++ ) {
      if (phrase[i] == ' ' || phrase[i] == '-') {
        char uppercase_letter = toupper(phrase[i + 1]);
        result[acronym_index++] = uppercase_letter;
      }
    }
  }

  return result;
}
