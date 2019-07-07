#include "pangram.h"

static bool is_alph_array_nonzero(int alpha[]) 
{
  bool result = true;
  for ( int i = 0; i < ALPHABET_LENGTH; i++ ) {
    result &= alpha[i];  
  }
  return result;
}

bool is_pangram(const char *sentence) {
  bool result = false;

  if ( sentence ) {
    int sentence_len = strlen(sentence);
    if ( sentence_len >= ALPHABET_LENGTH ) {
      int *alpha = (int*) calloc(ALPHABET_LENGTH, sizeof(int));
      
      for (int i = 0; i < sentence_len; i++) {
        int alph_index = (sentence[i] - 97) % ALPHABET_LENGTH;
        alpha[alph_index]++;
      }

      result = is_alph_array_nonzero(alpha);
    }
  }

  return result;
}
