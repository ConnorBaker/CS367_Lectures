#include <stdio.h>

void show_bytes(int x, int num_bytes);

int main() {
  short x =  15213;
  int  ix = (int) x; 
  short y = -15213;
  int  iy = (int) y;

  show_bytes(x, sizeof(x));
  show_bytes(ix, sizeof(ix));
  show_bytes(y, sizeof(y));
  show_bytes(iy, sizeof(iy));
}

void show_bytes(int x, int num_bytes) {
  int i;
  unsigned char *ptr = (unsigned char *)&x;
  for(i = 0; i < num_bytes; i++, ptr++) {
    printf("%.2x ", *ptr);
  }
  printf("\n");
}
