#include "word_count.h"

static word_count_word_t* find_word_struct(const char *token_string, word_count_word_t words[], int cur_index) {
  word_count_word_t* result = NULL;
  for ( int i = 0; i <= cur_index; i++) {
    if ( !strcmp( words[i].text, token_string ) ) {
      result = &words[i];
    }
  }

  return result;
}

int word_count(const char *input_text, word_count_word_t * words) {

  int unique_word_count = 0;

  //  Copy Array
  char* temp_input_text = (char*) malloc(sizeof(char) * (strlen(input_text) + 1)); 
  strcpy(temp_input_text, input_text);

  //  Tokenize strings 
  char* token = strtok(temp_input_text, " ,\n");

  //  Scrub input word_count_word_t struct  
  memset(words, 0, sizeof(word_count_word_t) * MAX_WORDS);

  int unique_word_index = 0;
  while ( token != NULL ) {
    word_count_word_t* existing_struct = find_word_struct(token, words, unique_word_index);

    if ( existing_struct ) {
      existing_struct->count++;
    } else {
      strcpy(words[unique_word_index].text, token);
      words[unique_word_index].count++;
      unique_word_count++;
      unique_word_index++;
    }

    token = strtok(NULL, " ,\n");
  }

  return unique_word_count;
}
