#include "rna_transcription.h"

static void replace_nucleotide(char* target, const char* src ) {
  if ( *src == 'G' ) {
    *target = 'C';
  } else if ( *src == 'C' ) {
    *target = 'G';
  } else if ( *src == 'T' ) {
    *target = 'A';
  } else if ( *src == 'A' ) {
    *target = 'U';
  } else {
    *target = '\0';
  }
}

char* to_rna(const char* dna) { 
  size_t strand_len = strlen(dna);
  char* result = (char*) malloc(sizeof(char) * strand_len + 1);

  for (size_t i = 0; i < strand_len; i++) {
    replace_nucleotide(result + i, dna + i); 

    if ( !result[i] ) {
      free(result);
      result = NULL;
      break;
    }
  }

  return result;
}
