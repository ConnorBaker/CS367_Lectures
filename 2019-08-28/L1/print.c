#include <stdio.h>

int main() {

  int a = 100;
  char c = 'z';
  char hw[13] = "Hello World!";
  double pi = 3.14159;
 
  printf("a: %d, \'%c\', 0x%x\n", a, a, a);
  printf("c: %d, '%c', 0x%x\n", c, c, c);
  printf("hw: \"%s\"\n", hw);
  printf("pi: %lf, %.2lf, %e\n", pi, pi, pi);

  return 0;
}
