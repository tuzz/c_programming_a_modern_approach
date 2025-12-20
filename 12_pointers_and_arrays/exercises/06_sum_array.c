#include <stdio.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

static int sum_array(const int *a, int n) {
  int sum = 0;

  for (const int *p = a; p < &a[n]; p++) {
    sum += *p;
  }

  return sum;
}

int main(void) {
  int a[5] = {1, 2, 3, 4, 5};

  printf("%d\n", sum_array(a, ARRAY_COUNT(a)));

  return 0;
}
