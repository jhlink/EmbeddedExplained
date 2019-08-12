#include "beer_song.h"

static void construct_verse(VerseTemplate *vt, int verse_count) {
  if ( verse_count == 2 ) {
    vt->start_template = &VERSE_START_PLURAL_TEMPLATE;
    vt->end_template = &VERSE_END_SINGLE_TEMPLATE;
  } else if ( verse_count == 1 ) {
    vt->start_template = &VERSE_START_SINGLE_TEMPLATE;
    vt->end_template = &VERSE_END_NONE_TEMPLATE;
  } else if ( verse_count == 0 ) {
    vt->start_template = &VERSE_START_FINAL_TEMPLATE;
    vt->end_template = &VERSE_END_FINAL_TEMPLATE;
  } else {
    vt->start_template = &VERSE_START_PLURAL_TEMPLATE;
    vt->end_template = &VERSE_END_PLURAL_TEMPLATE;
  }
}

static void fill_buffer(char* char_buf, VerseTemplate* vt, int verse_count) {
  int verse_start_end_index = 0;

  if ( verse_count < 2 ) {
    verse_start_end_index = sprintf(char_buf, "%s", *(vt->start_template));
  } else {
    verse_start_end_index = sprintf(char_buf, *(vt->start_template), verse_count, verse_count);
  }

  if ( verse_count < 3 ) {
    sprintf(char_buf + verse_start_end_index, "%s", *(vt->end_template));
  } else {
    sprintf(char_buf + verse_start_end_index, *(vt->end_template), verse_count - 1);
  }
}

void verse(char* char_buf, int verse_count) {
  VerseTemplate* vt = (VerseTemplate*) malloc(sizeof( VerseTemplate ));

  construct_verse(vt, verse_count);
  fill_buffer(char_buf, vt, verse_count);
}

void sing(char* char_buf, int start_verse, int end_verse) {
  memset(char_buf, DEFAULT_BUFFER_SIZE, '\0');
  int buffer_offset = 0;
  for (int i = start_verse; i >= end_verse; i--) {
    verse(char_buf + buffer_offset, i);  
    buffer_offset = strlen(char_buf); 
    assert(buffer_offset != 0);
    if ( i != end_verse ) char_buf[buffer_offset++] = '\n';
  }
}

