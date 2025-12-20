#include <stdio.h>
#include <limits.h>

static int *find_largest(int a[], int n) {
  int *largest = a;

  for (int *p = &a[1]; p < &a[n]; p++) {
    if (*p > *largest) {
      largest = p;
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
