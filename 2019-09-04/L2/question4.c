#include <stdio.h>

int main() {
  unsigned char A = 0x49;
  unsigned char B = 0x55;

  unsigned short C = 0x49;
  unsigned short D = 0x55;

  printf("Expressions...\n");
  printf("0x%.2x\n", A&B);
  printf("0x%.2x\n", A|B);
  printf("0x%.2x\n", A^B);
  printf("0x%.2x\n", ~B & 0xff);
  printf("0x%.2x\n", ~B);

  printf("--------\n");
  printf("Sizes of expressions...\n");
  printf("   A is %lu Bytes\n", sizeof(A));
  printf("   B is %lu Bytes\n", sizeof(B));
  printf(" A&B is %lu Bytes\n", sizeof(A&B));
  printf(" A|B is %lu Bytes\n", sizeof(A|B));
  printf(" A^B is %lu Bytes\n", sizeof(A^B));
  printf("  ~B is %lu Bytes\n", sizeof(~B));
  printf("A&&B is %lu Bytes\n", sizeof(A&&B));
  printf("A||B is %lu Bytes\n", sizeof(A||B));
  printf("  !B is %lu Bytes\n", sizeof(!B));
  printf(" A+B is %lu Bytes\n", sizeof(A+B));
  printf(" C+D is %lu Bytes\n", sizeof(C+D));

  printf("--------\n");
  printf("Fix for the problem: Mask with 0xFF to get the LSB only.\n");
  printf("0x%.2x\n", ~B & 0xFF);

  return 0;
}
