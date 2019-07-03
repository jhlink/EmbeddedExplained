#ifndef ACRONYM_H
#define ACRONYM_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

char *abbreviate(const char *phrase);
size_t count_delims(const char *src, const char *delim);

#endif
