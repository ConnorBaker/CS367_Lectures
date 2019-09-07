#include <stdio.h>

int main() {
  int a = 42;
  int *p;

  printf("a starts at %d\n", a);

  p = &a; // Assign p to the address of a
  *p = 12;// Dereference p to assign 12 to a

  printf("a is now %d\n", a);
}
