#include <stdio.h>

#define LEN 5

static int sum_two_dimensional_array(const int a[][LEN], int n) {
  int sum = 0;

  for (const int *p = a[0]; p < a[n]; p++) {
    sum += *p;
  }

  return sum;
}

int main(void) {
  int a[2][LEN] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10}
  };

  printf("sum: %d\n", sum_two_dimensional_array(a, 2));

  return 0;
}
