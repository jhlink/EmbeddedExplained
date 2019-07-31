#ifndef BEER_SONG_H
#define BEER_SONG_H

#include <string.h>
#include <stdio.h>

#define DEFAULT_BUFFER_SIZE 1024

static const char* VERSE_START_TEMPLATE = "%d bottles of beer on the wall, %d bottles of beer.\n";
static const char* VERSE_END_TEMPLATE = "Take one down and pass it around, %d bottles of beer on the wall.\n";

void verse(char* char_buf, int verse_count); 
void sing(char* char_buf, int start_verse, int end_verse);

#endif
