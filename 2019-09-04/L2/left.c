#include <stdio.h>
#include <math.h>

int main() {
  int x = 0xABCD;
  int k;
  int w = 32;

  int ls, md;

  for(k = 0; k < w; k++) {
    ls = x << k;
    md = (x * (long)pow(2,k))%((long)pow(2,w));
    if(ls == md) {
      printf("[%2d] 0x%10x == 0x%10x\n", k, ls, md);
    }
    else {
      printf("[%2d] 0x%10x != 0x%10x\n", k, ls, md);
    }
  }
  return 0;
}
