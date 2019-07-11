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

static int match_nth_meet_day(char meet_day[]) {
  int result = 0;  
  for ( int i = 0; i < 4; i++ ) {
    if ( !strcmp(meet_day, NUMBERED_MEET_DAY[i]) ) {
      result = i;
    }
  }

  return result;
}

static void update_month_and_year(int year, int month, int day, struct tm* timeinfo) {
  timeinfo->tm_year = year - 1900;
  timeinfo->tm_mon = month - 1;
  timeinfo->tm_mday = day;
  mktime(timeinfo);
}

int meetup_day_of_month(int year, int month, char meet_day[], char week_day[]) {
  int result = 0;
  struct tm * timeinfo; 

  timeinfo = (struct tm *) calloc(1, sizeof(struct tm));

  int matched_weekday_index = match_weekday(week_day);

  if ( !strcmp(meet_day, TEENTH_MEET_DAY) ) {
    update_month_and_year(year, month, 13, timeinfo);

    while ( matched_weekday_index != timeinfo->tm_wday && timeinfo->tm_mday < 20 ) {
      timeinfo->tm_mday++;
      mktime(timeinfo);
    }
  } else if ( !strcmp(meet_day, LAST_MEET_DAY) ) {
    int max_cal_days = MONTH_DAYS[month - 1]; 
    update_month_and_year(year, month, max_cal_days, timeinfo);
    if ( timeinfo->tm_mon != month - 1) {
      timeinfo->tm_mday--;
      mktime(timeinfo);
    }

    while ( matched_weekday_index != timeinfo->tm_wday 
            && timeinfo->tm_mday > (max_cal_days - 7) 
            && month - 1 == timeinfo->tm_mon ) {
      timeinfo->tm_mday--;
      mktime(timeinfo);
    }
  } else {
    int week_day_offset = match_nth_meet_day(meet_day) * 7;
    update_month_and_year(year, month, 1, timeinfo);
    timeinfo->tm_mday += week_day_offset;
    mktime(timeinfo);

    int offset = timeinfo->tm_wday;

    if ( matched_weekday_index != offset ) {
      int weekoffset = matched_weekday_index > offset ? matched_weekday_index : matched_weekday_index + 7;

      timeinfo->tm_mday += weekoffset - offset;
    }
  }

  result = timeinfo->tm_mday;
  free(timeinfo);
  return result;
}
