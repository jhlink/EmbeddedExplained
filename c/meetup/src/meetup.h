#ifndef MEETUP_H
#define MEETUP_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

static const char TEENTH_MEET_DAY[] = "teenth";
static const char LAST_MEET_DAY[] = "last";
static const int MONTH_DAYS[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static const char *WEEK_DAYS[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
static const char *NUMBERED_MEET_DAY[] = { "first", "second", "third", "fourth", "fifth" };

int meetup_day_of_month(int year, int month, char meet_day[], char week_day[]); 

#endif
