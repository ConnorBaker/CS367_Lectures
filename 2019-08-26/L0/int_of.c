#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
// Tip: Try 3000000000 and then 4000000000

  // Always check the right number of arguments
  if(argc != 2) {
    printf("Usage: %s <number>\n", argv[0]);
    return -1;
  }

  // Convert the argument into a long safely.
  errno = 0;
  long val = strtol(argv[1], NULL, 10);
  if(errno == EINVAL || errno == ERANGE) {
    printf("There was a problem converting your number to a decimal.\n");
    return -1;
  }

  // Print out the expression and show it's square.
  printf(" x  = %ld\n", val);
  printf("x*x = %ld\n", val * val);
  printf("Is x*x >= 0? %s\n", (val * val)>=0?"Yes - Math Works!":"No :(");
  return 0;
}

