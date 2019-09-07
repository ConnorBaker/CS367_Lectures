#include <stdio.h>

int main() {
  char name[100];
  int age, gnum;
  double gpa;
  int conversions;
  conversions = scanf("%s %d/%d %lf", name, &age, &gnum, &gpa);
  printf("%s %d/%d %.2lf\n", name, age, gnum, gpa);
  printf("Conversions: %d\n", conversions);

  return 0;
}
