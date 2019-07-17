#include "vendor/unity.h"
#include "../src/nucleotide_count.h"
#include <stdlib.h>
#include <string.h>

void setUp(void)
{

}

void tearDown(void)
{
}

static void test_strand_count(const char *dna_strand, const char *expected)
{
   char *actual_count = count(dna_strand);

   TEST_ASSERT_TRUE(strcmp(actual_count, expected) == 0);
   free(actual_count);
}

static void test_empty_strand(void)
{
   const char *dna_strand = "";
   const char *expected = "A:0 C:0 G:0 T:0";

   test_strand_count(dna_strand, expected);
}

static void test_repeated_nucleotide_g(void)
{
   const char *dna_strand = "GGGGGGG";
   const char *expected = "A:0 C:0 G:7 T:0";

   test_strand_count(dna_strand, expected);
}

static void test_repeated_nucleotide_a(void)
{
   const char *dna_strand = "AAAAAAA";
   const char *expected = "A:7 C:0 G:0 T:0";

   test_strand_count(dna_strand, expected);
}

static void test_repeated_nucleotide_c(void)
{
   const char *dna_strand = "CCCCCCC";
   const char *expected = "A:0 C:7 G:0 T:0";

   test_strand_count(dna_strand, expected);
}

static void test_repeated_nucleotide_t(void)
{
   const char *dna_strand = "TTTTTTT";
   const char *expected = "A:0 C:0 G:0 T:7";

   test_strand_count(dna_strand, expected);
}

static void test_multiple_nucleotides(void)
{
   TEST_IGNORE();
   const char *dna_strand =
       "AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC";
   const char *expected = "A:20 C:12 G:17 T:21";

   test_strand_count(dna_strand, expected);
}

static void test_invalid_nucleotide(void)
{
   TEST_IGNORE();
   const char *dna_strand = "AGXXACT";
   const char *expected = "";

   test_strand_count(dna_strand, expected);
}

int main(void)
{
   UnityBegin("test/test_nucleotide_count.c");

   RUN_TEST(test_empty_strand);
   RUN_TEST(test_repeated_nucleotide_g);
   RUN_TEST(test_repeated_nucleotide_a);
   RUN_TEST(test_repeated_nucleotide_c);
   RUN_TEST(test_repeated_nucleotide_t);
   RUN_TEST(test_multiple_nucleotides);
   RUN_TEST(test_invalid_nucleotide);

   return UnityEnd();
}
