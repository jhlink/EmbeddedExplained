#ifndef MEETUP_H
#define MEETUP_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

static const char TEENTH_MEET_DAY[] = "teenth";
static const char *WEEK_DAYS[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
static const char *NUMBERED_MEET_DAY[] = { "first", "second" };

int meetup_day_of_month(int year, int month, char meet_day[], char week_day[]); 

#endif
