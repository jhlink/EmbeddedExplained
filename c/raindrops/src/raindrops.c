#include "raindrops.h"

char *convert(char result[], int drops) {

  if ( drops % 3 == 0 ) {
    sprintf(result, "%s", THREE_PLING);
  } else {
    sprintf(result, "%d", drops);
  }

  return result;
}

