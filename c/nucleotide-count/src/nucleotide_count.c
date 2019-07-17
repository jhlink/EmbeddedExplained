#include "nucleotide_count.h"

char* count(const char dna_strand[]) 
{
  size_t strand_len = strlen(dna_strand);
  nucleo_count* nucleo_ct = (nucleo_count*) calloc(1, sizeof(nucleo_count)); 

  if (strand_len > 0) {

  }

  int sz = snprintf(NULL, 0, NUCLEO_COUNT_STRING_TEMPLATE, nucleo_ct->A, nucleo_ct->C, nucleo_ct->G, nucleo_ct->T );   

  char* nucleo_ct_result = (char*) malloc(sz + 1); 

  snprintf(nucleo_ct_result, sz + 1, NUCLEO_COUNT_STRING_TEMPLATE, nucleo_ct->A, nucleo_ct->C, nucleo_ct->G, nucleo_ct->T );   

  free(nucleo_ct);

  return nucleo_ct_result;
}
