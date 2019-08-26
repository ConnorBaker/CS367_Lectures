#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BIG_NUM 1073741824

void double_fun(int index);

int main(int argc, char *argv[]) {
  int index;

  // Always check the right number of arguments
  if(argc != 2) {
    printf("Usage: %s <index>\n", argv[0]);
    return -1;
  }

  // Convert the argument into a long safely.
  errno = 0;
  index = strtol(argv[1], NULL, 10);
  if(errno == EINVAL || errno == ERANGE) {
    printf("There was a problem converting your number to a decimal.\n");
    return -1;
  }

  double_fun(index);
  return 0;
}

void double_fun(int index) {
  double d[1] = {3.14};
  long a[2];
  // Overwrite the given index with a big number;
  a[index] = BIG_NUM;
  printf("Setting a[%ld] = %ld; d[0] = %lf\n", index, BIG_NUM, d[0]);
}

