#include <stdio.h>

int main() {
  int x = 0x1234567;
  unsigned char *bp = (unsigned char *)&x;
  printf("0x%x\n", *(bp + 2));
  return 0;
}
