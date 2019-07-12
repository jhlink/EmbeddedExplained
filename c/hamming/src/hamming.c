#include "hamming.h"

static int count_char_diffs(char strand_a[], char strand_b[], int strand_len) {
  int char_diffs = 0;  
  for ( int i = 0; i < strand_len; i++ ) {
    if (strand_a[i] != strand_b[i]) char_diffs++;
  }
  return char_diffs;
}

int compute(char strand_a[], char strand_b[]) {
  int result = 0;
  if ( !strand_a || !strand_b ) {
    result = -1; 
  } else if ( strlen(strand_a) != strlen(strand_b) ) {
    result = -1;
  } else {
    result = count_char_diffs(strand_a, strand_b, strlen(strand_a));
  }
  return result;  
}
