#include "pangram.h"

static bool is_alph_array_nonzero(int alpha[])
{
  bool result = true;
  for ( int i = 0; i < ALPHABET_LENGTH; i++ ) {
    result = result && alpha[i];
  }

  return result;
}

static int get_lwr_case_ascii_value(char input_char) {
  char lower_case_letter = tolower(input_char);
  int alph_index = (lower_case_letter - 97) % ALPHABET_LENGTH;

  return alph_index;
}

bool is_pangram(const char *sentence) {
  bool result = false;
  int alpha[ALPHABET_LENGTH] = {0};

  if ( sentence ) {
    int sentence_len = strlen(sentence);
    if ( sentence_len >= ALPHABET_LENGTH ) {

      for (int i = 0; i < sentence_len; i++) {
        if ( isalpha(sentence[i]) ) {
          int alph_index = get_lwr_case_ascii_value(sentence[i]);
          alpha[alph_index]++;
        }
      }

      result = is_alph_array_nonzero(alpha);
    }
  }

  return result;
}

