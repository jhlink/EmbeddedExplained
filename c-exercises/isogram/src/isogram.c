#include "isogram.h"

bool shouldSkip(const char ichar) {
  bool result = false;
  if ( ichar == ' ' ) {
    result = true; 
  } else if ( ichar == '-') {
    result = true;
  }

  return result;
}

bool is_isogram(const char phrase[])
{
  bool result = false;
  if ( phrase ) {
    size_t stringSize = strlen(phrase);
    result = stringSize == 0;

    if ( stringSize ) {
      result = is_isogram_helper(phrase, stringSize);
    }
  }

  return result;
}

bool is_isogram_helper(const char phrase[], size_t istringSize) {
  bool result = true;

  const int alphabet_limit = 26;
  char* alphabet_array = (char*) malloc(sizeof(char) * alphabet_limit);
  memset(alphabet_array, 0, alphabet_limit);

  size_t strIndex = 0;
  while ( strIndex < istringSize ) {
    char currChar = phrase[strIndex]; 

    if ( !shouldSkip(currChar) ) {
      currChar = tolower(currChar);
      int alphabet_charValue = currChar - 97; 

      if ( alphabet_array[alphabet_charValue] ) {
        result = false;
        break;
      } else {
        alphabet_array[alphabet_charValue] = 1;
      }
    }

    strIndex++; 
  }

  free(alphabet_array);

  return result;
}
