#include "raindrops.h"

char *convert(char result[], int drops) {

  if ( drops % 3 == 0 ) {
    sprintf(result, "%s", THREE_PLING);
  } 
  
  if ( drops % 5 == 0 ) {
    sprintf(result, "%s", FIVE_PLANG);
  } 
  
  if ( drops % 3 != 0 && drops % 5 != 0) {
    sprintf(result, "%d", drops);
  }

  return result;
}

