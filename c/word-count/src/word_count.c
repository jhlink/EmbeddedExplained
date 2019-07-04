#include "word_count.h"

int word_count(const char *input_text, word_count_word_t * words) {
  int unique_word_count = 0;

  word_count_word_t one_word = { .count = 1 };  
  strcpy(one_word.text, input_text);
  words[0] = one_word;

  unique_word_count++;

  return unique_word_count;
}
