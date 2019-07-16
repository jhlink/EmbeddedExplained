#include "rna_transcription.h"

static void replace_nucleotide(char* target) {
  if ( *target == 'G' ) {
    *target = 'C';
  } else if ( *target == 'C' ) {
    *target = 'G';
  }
}

char* to_rna(const char* dna) { 
  size_t strand_len = strlen(dna);
  char* result = (char*) malloc(sizeof(char) * strand_len + 1);
  strcpy(result, dna);

  for (size_t i = 0; i < strand_len; i++) {
    replace_nucleotide(result + i); 
  }

  return result;
}
