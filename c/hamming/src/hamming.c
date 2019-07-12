#include "hamming.h"

int compute(char strand_a[], char strand_b[]) {
  int result = 0;
  if ( !strand_a || !strand_b ) {
    result = -1; 
  } else {
    result = strcmp(strand_a, strand_b);
  }
  return result;  
}
