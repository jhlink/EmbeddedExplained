#include "word_count.h"

static void initialize_word_struct(word_count_word_t * word_struct) {
  memset(word_struct->text, 0, MAX_WORD_LENGTH);  
  word_struct->count = 0;
}

int word_count(const char *input_text, word_count_word_t * words) {
  int unique_word_count = 0;

  //  Copy Array
  char* temp_input_text = (char*) malloc(sizeof(char) * (strlen(input_text) + 1)); 
  strcpy(temp_input_text, input_text);

  //  Tokenize strings 
  char* token = strtok(temp_input_text, " ");

  int unique_word_index = 0;
  while ( token != NULL ) {
    initialize_word_struct(words + unique_word_index);

    strcpy(words[unique_word_index].text, token);
    words[unique_word_index].count++;

    unique_word_count++;
    unique_word_index++;
    token = strtok(NULL, " ");
  }

  return unique_word_count;
}
