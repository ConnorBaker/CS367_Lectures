#include <stdio.h>

int main() {
  float x = 1e20; // 1 * pow(10,20)
  float y = -1e20;// -1 * pow(10,20)
  float z = 3.14; // 3.14

  // Print out the two groupings.
  printf("x =  %e\ny = %e\nz =  %e\n", x, y, z);
  // (x + y)  + z
  printf("(x +  y) + z  == %e\n", (x+y)+z);
  //  x +  (y + z)
  printf(" x + (y  + z) == %e\n", x+(y+z));

  return 0;
}

