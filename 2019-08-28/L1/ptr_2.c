#include <stdio.h>

int main() { 
  int a = 42, b = 16;
  int *p, *q;
  p = &a;  
  q = &b;   
  *q = *p; 
  p = q;    
  printf("%d %d %d %d\n",a,b,*p,*q);
}
