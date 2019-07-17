#include "nucleotide_count.h"

static void create_nucleo_result_string(char* dest_buff[], const nucleo_count* nucleo_ct) 
{
  if ( nucleo_ct ) {
    int str_sz = snprintf(NULL, 0, NUCLEO_COUNT_STRING_TEMPLATE, nucleo_ct->A, nucleo_ct->C, nucleo_ct->G, nucleo_ct->T );   
    *dest_buff = (char*) realloc(*dest_buff, str_sz + 1); 
    snprintf(*dest_buff, str_sz + 1, NUCLEO_COUNT_STRING_TEMPLATE, nucleo_ct->A, nucleo_ct->C, nucleo_ct->G, nucleo_ct->T );   
  } else { 
    *dest_buff = (char*) malloc(1); 
    *dest_buff[0] = '\0';
    // *dest_buff = "";  // fails in the memory free method in test suite
  }
}

static int parse_strand(nucleo_count* nucleo_ct, const char strand[]) 
{
  size_t strand_len = strlen(strand);

  if ( strand_len ) {
    for ( size_t i = 0; i < strand_len; i++ ) {
      if (strand[i] == 'G') {
        nucleo_ct->G++;
      } else if (strand[i] == 'T') {
        nucleo_ct->T++;
      } else if (strand[i] == 'C') {
        nucleo_ct->C++;
      } else  if (strand[i] == 'A') {
        nucleo_ct->A++;
      } else {
        strand_len = -1;
        break;
      }
    }
  }

  return strand_len;
}

char* count(const char dna_strand[]) 
{
  nucleo_count* nucleo_ct = (nucleo_count*) calloc(1, sizeof(nucleo_count)); 
  char* nucleo_ct_result = NULL;

  int result = parse_strand(nucleo_ct, dna_strand);

  if ( result < 0 ) {
    free(nucleo_ct);
    nucleo_ct = NULL;
  }

  create_nucleo_result_string(&nucleo_ct_result, nucleo_ct);

  return nucleo_ct_result;
}
