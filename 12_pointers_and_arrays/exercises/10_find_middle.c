#include <stdio.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

static int *find_middle(int a[], int n) {
  return a + n / 2;
}

int main(void) {
  int a[5] = {1, 2, 3, 4, 5};

  int *middle = find_middle(a, ARRAY_COUNT(a));
  printf("middle: %d\n", *middle);

  return 0;
}
