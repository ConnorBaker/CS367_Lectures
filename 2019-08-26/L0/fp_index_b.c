#include <stdio.h>

int main() {
  float index;
  int counter;

  printf("Let's count until math breaks!\n");

  for(index = 0, counter=0; index >= 0; index++, counter++) {
    // Print a . every 100 million to show progress.
    if(counter%100000000 == 0) {
      fprintf(stderr, "."); // stderr is non-buffering
      printf("- Value is %.2f\n", index);
      counter = 0;
    }
  }

  printf("Math broke when index became %d\n", index);
  return 0;
}
