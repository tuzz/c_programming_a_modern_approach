#include <stdio.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

static void store_zeros(int a[], int n) {
  int i;

  for (i = 0; i < n; i++)
    a[i] = 0;
}

int main(void) {
  int a[5] = {1, 2, 3, 4, 5};

  store_zeros(a, ARRAY_COUNT(a));

  for (size_t i = 0; i < ARRAY_COUNT(a); i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
