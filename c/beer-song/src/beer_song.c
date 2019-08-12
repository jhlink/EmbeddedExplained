#include "beer_song.h"

void verse(char* char_buf, int verse_count) {
  int verse_start_end_index = sprintf(char_buf, verse_count > 1 ? VERSE_START_PLURAL_TEMPLATE : VERSE_START_SINGLE_TEMPLATE, verse_count, verse_count);

  if ( verse_count == 2 ) {
    sprintf(char_buf + verse_start_end_index, "%s", VERSE_END_SINGLE_TEMPLATE);
  } else if ( verse_count == 1 ) {
    sprintf(char_buf + verse_start_end_index, "%s", VERSE_END_NONE_TEMPLATE);
  } else {
    sprintf(char_buf + verse_start_end_index, VERSE_END_PLURAL_TEMPLATE, verse_count - 1);
  }
}

void sing(char* char_buf, int start_verse, int end_verse) {
  printf(char_buf, "%d %d", start_verse, end_verse);
}

