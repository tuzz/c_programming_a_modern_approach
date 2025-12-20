#include <stdio.h>
#include <limits.h>

static void find_two_largest(int a[], int n, int *largest, int *second_largest) {
  *largest = INT_MIN;
  *second_largest = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (a[i] > *second_largest) {
      if (a[i] > *largest) {
        *second_largest = *largest;
        *largest = a[i];
      } else {
        *second_largest = a[i];
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
