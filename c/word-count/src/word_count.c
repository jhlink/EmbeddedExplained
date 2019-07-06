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

static bool is_value_within_excl_range(int value, int lwr_range, int upr_range) {
  return value > lwr_range && value < upr_range;
}

static bool is_surr_by_alph(const char* str, int index) {
  bool result = false;
  if ( is_value_within_excl_range(index, 0, MAX_WORD_LENGTH - 1) ) {
    result = isalpha(str[index - 1]) && isalpha(str[index + 1]);
  }
  return result;
}

static void sanitize_string(char input_string[]) {
  int i = 0;
  while ( input_string[i] != '\0' && i < MAX_WORD_LENGTH ) {
    char curr_char = input_string[i];

    if ( ispunct( curr_char ) ) {
      if ( curr_char == '\'' && is_surr_by_alph(input_string, i)) {

      } else {
        input_string[i] = ' ';
      }

    }

    input_string[i] = tolower(input_string[i]);
    i++;
  }
}

int word_count(const char *input_text, word_count_word_t * words) {
  int unique_word_count = 0;

  //  Copy Array
  char* temp_input_text = (char*) malloc(sizeof(char) * (strlen(input_text) + 1));
  strcpy(temp_input_text, input_text);
  sanitize_string(temp_input_text);

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

  free(temp_input_text);
  return unique_word_count;
}
