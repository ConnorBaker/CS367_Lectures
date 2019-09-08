#include <stdio.h>

int main() {
  short a = 0x3C;
  short b = 0x95;

  printf("0x%.2x & 0x%.2x == 0x%.2x\n", a, b, a&b);
  return 0;
}
