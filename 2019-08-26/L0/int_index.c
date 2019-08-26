#include <stdio.h>

int main() {
  int index;

  printf("Let's count until math breaks!\n");

  for(index = 0; index >= 0; index++) {
    // Print a . every 100 million increments to show its still working
    if(index%100000000 == 0) {
      fprintf(stderr, "."); // stderr is non-buffering
    }
  }

  printf("Math broke when index became %d\n", index);
  return 0;
}
