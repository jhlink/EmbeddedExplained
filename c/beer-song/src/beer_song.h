#ifndef BEER_SONG_H
#define BEER_SONG_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEFAULT_BUFFER_SIZE 1024

typedef struct {
  const char** start_template;
  const char** end_template;
} VerseTemplate;

static const char* VERSE_START_PLURAL_TEMPLATE = "%d bottles of beer on the wall, %d bottles of beer.\n";
static const char* VERSE_START_SINGLE_TEMPLATE = "1 bottle of beer on the wall, 1 bottle of beer.\n";
static const char* VERSE_START_FINAL_TEMPLATE = "No more bottles of beer on the wall, no more bottles of beer.\n";

static const char* VERSE_END_PLURAL_TEMPLATE = "Take one down and pass it around, %d bottles of beer on the wall.\n";
static const char* VERSE_END_SINGLE_TEMPLATE = "Take one down and pass it around, 1 bottle of beer on the wall.\n";
static const char* VERSE_END_NONE_TEMPLATE = "Take it down and pass it around, no more bottles of beer on the wall.\n";
static const char* VERSE_END_FINAL_TEMPLATE = "Go to the store and buy some more, 99 bottles of beer on the wall.\n";

void verse(char* char_buf, int verse_count); 
void sing(char* char_buf, int start_verse, int end_verse);

#endif
