#include <stdio.h>

int main() {
  float index;
  int counter = 0;  // For printing .s

  printf("Let's count until math breaks!\n");

  for(index = 0; index >= 0; index++) {
    // Print a . every 100 million increments to show progress.
    if(counter%100000000 == 0) {
      fprintf(stderr, "."); // stderr is non-buffering
      counter = 0;
    }
    counter++;
  }

  printf("Math broke when index became %d\n", index);
  return 0;
}
