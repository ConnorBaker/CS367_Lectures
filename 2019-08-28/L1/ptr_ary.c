#include <stdio.h>

int main() {
  int nums[5] = {1, 6, 10, 42, -14};
  int *p_nums = NULL;

  p_nums = nums;
  // Address of the array
  printf("Address of nums:           %p\n", nums);
  printf("Address p_nums points to:  %p\n", p_nums);

  printf("----------\n");
  // Address of the fourth number with [] notation
  printf("Address of nums[3]:        %p\n", &nums[3]);
  printf("Address of p_nums[3]:      %p\n", &p_nums[3]);

  printf("----------\n");
  // Address of the fourth number with pointer arithmetic
  printf("Address of nums + 3:       %p\n", p_nums + 3);
  printf("Address of p_nums + 3:     %p\n", p_nums + 3);

  printf("----------\n");
  // Access the fourth number with [] notation
  printf("p_nums[3] ==   %d\n", p_nums[3]);
  // Access the fourth number with pointer arithmetic
  printf("*(p_nums+3) == %d\n", *(p_nums + 3));

  return 0;
}
