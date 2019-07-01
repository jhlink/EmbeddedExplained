#ifndef ISOGRAM_H
#define ISOGRAM_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool is_isogram(const char phrase[]);
bool is_isogram_helper(const char phrase[], size_t stringSize); 
bool shouldSkip(const char ichar);

#endif
