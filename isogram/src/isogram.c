#include "isogram.h"


bool parseString(const char phrase[]); 

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
    size_t string_size = strlen(phrase);
    result = string_size == 0;

    if ( string_size ) {
      parseString(phrase);
    }
  }

  return result;
}

bool parseString(const char phrase[]) {
  const int alphabet_limit = 26;
  char* alphabet_array = (char*) malloc(sizeof(char) * 26);
  memset(alphabet_array, 0, 26);

  size_t str_index = 0;
  while ( str_index < string_size ) {
    result = true;
    char currChar = phrase[str_index]; 

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

    str_index++; 
  }

  free(alphabet_array);
}
