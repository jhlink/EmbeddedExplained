#include "beer_song.h"

void verse(char* char_buf, int verse_count) {
  printf(char_buf, "%d", verse_count);
}

void sing(char* char_buf, int start_verse, int end_verse) {
  printf(char_buf, "%d %d", start_verse, end_verse);
}

