#include "raindrops.h"

char *convert(char result[], int drops) {
  int char_buff_pos = 0;

  if ( drops % 3 == 0 ) {
    char_buff_pos += sprintf(result, "%s", THREE_PLING);
  } 
  
  if ( drops % 5 == 0 ) {
    char_buff_pos += sprintf(result + char_buff_pos, "%s", FIVE_PLANG);
  } 

  if ( drops % 7 == 0 ) {
    char_buff_pos += sprintf(result + char_buff_pos, "%s", SEVEN_PLONG);
  } 
  
  if ( drops % 3 != 0 && drops % 5 != 0 && drops % 7 != 0 ) {
    sprintf(result, "%d", drops);
  }

  return result;
}

