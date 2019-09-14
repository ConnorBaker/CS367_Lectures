#include <stdio.h>

// Macro!  Just for fun.
#define RELATION(x,y) printf("%12s %2s %-12s\n", #x,x<y?"<":x>y?">":"==",#y)

int main() {
  char x = 120;
  unsigned char ux = (unsigned char) x;
  
  char y = -120;
  unsigned char uy = (unsigned char) y;

  printf("x: %4d, ux: %4d\n", x, ux);
  printf("y: %4d, uy: %4d\n", y, uy);

  printf("\nRelations...\n");

  // Constants
  RELATION(0,0U);
  RELATION(-1,0);
  RELATION(-1,0U);
  RELATION(2147483647,-2147483648);
  RELATION(2147483647U,-2147483648);
  RELATION(-1,-2);
  RELATION((unsigned)-1, -2);
  RELATION(2147483647,2147483648U);
  RELATION(2147483647,(int)2147483648U);
  
 
  return 0;
}
