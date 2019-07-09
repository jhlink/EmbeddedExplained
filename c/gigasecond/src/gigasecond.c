#include "gigasecond.h"

time_t gigasecond_after(time_t raw_date) {
  unsigned long g_sec = raw_date + GIGA_SEC;

  return g_sec;  
}
