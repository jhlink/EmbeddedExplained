#include "beer_song.h"

void verse(char* char_buf, int verse_count) {
  int verse_start_end_index = sprintf(char_buf, VERSE_START_TEMPLATE, verse_count, verse_count);
  sprintf(char_buf + verse_start_end_index, VERSE_END_TEMPLATE, verse_count - 1);
}

void sing(char* char_buf, int start_verse, int end_verse) {
  printf(char_buf, "%d %d", start_verse, end_verse);
}

