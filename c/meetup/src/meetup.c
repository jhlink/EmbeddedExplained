#include "meetup.h"

static int match_weekday(char week_day[]) {
  int result = 0;  
  for ( int i = 0; i < 7; i++ ) {
    if ( !strcmp(week_day, WEEK_DAYS[i]) ) {
      result = i;
    }
  }

  return result;
}

int meetup_day_of_month(int year, int month, char meet_day[], char week_day[]) {
  struct tm * timeinfo; 
  timeinfo = (struct tm *) calloc(1, sizeof(struct tm));

  if ( !strcmp(meet_day, TEENTH_MEET_DAY) ) {
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = 13;
    mktime(timeinfo);

    int temp_weekday = match_weekday(week_day);

    while ( temp_weekday != timeinfo->tm_wday && timeinfo->tm_wday < 20) {
      timeinfo->tm_mday++;
      mktime(timeinfo);
    }
  }

  return timeinfo->tm_mday;
}
