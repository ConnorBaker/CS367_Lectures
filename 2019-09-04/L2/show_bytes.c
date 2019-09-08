#include <stdio.h>

void show_bytes(unsigned char *, size_t);

int main() {
  char c = 0xF2;
  short s = 0xABCD;
  int i = 0xFEEDBEEF;
  long l = 0xCAFE1337DEAD1701;

  show_bytes((unsigned char *)&c, sizeof(char));
  show_bytes((unsigned char *)&s, sizeof(short));
  show_bytes((unsigned char *)&i, sizeof(int));
  show_bytes((unsigned char *)&l, sizeof(long));
 
  return 0;
}

void show_bytes(unsigned char *start, size_t len) {
  size_t i;
  for(i = 0; i < len; i++) {
    printf("%p\t0x%.2x\n", start + i, start[i]);
  }
  printf("\n");
}
