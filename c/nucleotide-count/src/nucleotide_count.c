#include "nucleotide_count.h"

static void create_nucleo_result_string(char dest_buff[], const nucleo_count* nucleo_ct) {
  if ( nucleo_ct ) {
    int str_sz = snprintf(NULL, 0, NUCLEO_COUNT_STRING_TEMPLATE, nucleo_ct->A, nucleo_ct->C, nucleo_ct->G, nucleo_ct->T );   

    dest_buff = (char*) realloc(dest_buff, str_sz + 1); 
    snprintf(dest_buff, str_sz + 1, NUCLEO_COUNT_STRING_TEMPLATE, nucleo_ct->A, nucleo_ct->C, nucleo_ct->G, nucleo_ct->T );   
  } else {
    dest_buff = "";
  }
}

char* count(const char dna_strand[]) 
{
  size_t strand_len = strlen(dna_strand);
  nucleo_count* nucleo_ct = (nucleo_count*) calloc(1, sizeof(nucleo_count)); 
  char* nucleo_ct_result = (char*) malloc(2);

  if (strand_len > 0) {
    for ( size_t i = 0; i < strand_len; i++ ) {
      if (dna_strand[i] == 'G') {
        nucleo_ct->G++;
      } else if (dna_strand[i] == 'T') {
        nucleo_ct->T++;
      } else if (dna_strand[i] == 'C') {
        nucleo_ct->C++;
      } else  if (dna_strand[i] == 'A') {
        nucleo_ct->A++;
      } else {
        free(nucleo_ct);
        nucleo_ct = NULL;
        break;
      }
    }
  }

  create_nucleo_result_string(nucleo_ct_result, nucleo_ct);

  return nucleo_ct_result;
}
