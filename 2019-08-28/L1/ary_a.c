#include <stdio.h>

int main() {
  char name[10] = "John"; // Create an array of 10 chars
  char *c_ptr = NULL; // Pointer to a character
  c_ptr = name; // c_ptr and name have same value (address of array)

  // name == c_ptr  
  printf("--Initial Assignment-----------------\n");
  printf("name  = %s\nc_ptr = %s\n", name, c_ptr);

  c_ptr = c_ptr + 1; // Legal (c_ptr[0] now equals name[1])
  printf("--After: c_ptr += 1------------------\n");
  printf("name  = %s\nc_ptr = %s\n", name, c_ptr);

  return 0;
}
