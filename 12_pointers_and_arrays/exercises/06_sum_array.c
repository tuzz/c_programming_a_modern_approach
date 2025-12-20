#include <stdio.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

static int sum_array(const int a[], int n) {
  int i, sum;

  sum = 0;
  for (i = 0; i < n; i++)
    sum += a[i];
  return sum;
}

int main(void) {
  int a[5] = {1, 2, 3, 4, 5};

  printf("%d\n", sum_array(a, ARRAY_COUNT(a)));

  return 0;
}
