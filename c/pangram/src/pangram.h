#ifndef PANGRAM_H
#define PANGRAM_H

#define ALPHABET_LENGTH 26

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool is_pangram(const char *sentence);

#endif
