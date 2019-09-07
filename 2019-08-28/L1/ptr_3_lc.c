#include <stdio.h>

int main() {  
  int a = 42;  
  int b = 16;  
  printf("%d, %d\n", a, b);  
  swap(&a, &b);  
  printf("%d, %d\n", a, b);  
  return 0;  
}  
