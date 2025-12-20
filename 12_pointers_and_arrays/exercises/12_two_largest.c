#include <stdio.h>
#include <limits.h>

static void find_two_largest(int *a, int n, int *largest, int *second_largest) {
  *largest = INT_MIN;
  *second_largest = INT_MIN;

  for (int *p = a; p < &a[n]; p++) {
    if (*p > *second_largest) {
      if (*p > *largest) {
        *second_largest = *largest;
        *largest = *p;
      } else {
        *second_largest = *p;
      }
    }
  }
}

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  int a[5] = {5, 2, 3, 4, 1};

  int largest = -1;
  int second_largest = -1;
  find_two_largest(a, ARRAY_COUNT(a), &largest, &second_largest);

  printf("largest: %d\n", largest);
  printf("second_largest: %d\n", second_largest);

  return 0;
}
