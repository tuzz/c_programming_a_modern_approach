#include <stdio.h>
#include <limits.h>

static int *find_largest(int a[], int n) {
  int *largest = &a[0];

  for (int i = 1; i < n; i++) {
    if (a[i] > *largest) {
      largest = &a[i];
    }
  }

  return largest;
}

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  int a[5] = {1, 5, 3, 4, 2};
  int *p = find_largest(a, ARRAY_COUNT(a));
  printf("largest: %d\n", *p);

  return 0;
}
