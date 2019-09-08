#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// Prototypes
static void print_bits_char(char value);

int main() {
  // Seed the PRNG with the current time in seconds
  srand(time(NULL));

  // Generate a pos rand value in range for a signed char (limits.h constant)
  char value = rand()%SCHAR_MAX;
  char mask;

  printf("1) Set bits 1 and 2 to a 1.\n");
  mask = 0x6; // 00000110
  printf("\tvalue:     0x%02x ", value);
  print_bits_char(value);
  printf("\tWith mask: 0x%02x ", value | mask);
  print_bits_char(value | mask);

  printf("2) Clear bits 1 and 2 (set to a 0).\n");
  mask = ~0x6; // 11111001
  printf("\tvalue:     0x%02x ", value);
  print_bits_char(value);
  printf("\tWith mask: 0x%02x ", value & mask);
  print_bits_char(value & mask);

  printf("3) Flip bits 1 and 2.\n");
  mask = 0x6; // 00000110
  printf("\tvalue:     0x%02x ", value);
  print_bits_char(value);
  printf("\tWith mask: 0x%02x ", value ^ mask);
  print_bits_char(value ^ mask);

  return 0;
}

// Local scope function (static) to print bits
static void print_bits_char(char value) {
  int i;
  printf("(");
  for(i = CHAR_BIT-1; i >= 0; i--) {
    printf("%d", (value>>i)&0x1);
  }
  printf(")\n");
}
