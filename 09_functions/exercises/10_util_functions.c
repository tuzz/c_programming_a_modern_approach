#include <stdio.h>
#include <limits.h>

static int largest_element(int a[], int n) {
  int largest = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (a[i] > largest) {
      largest = a[i];
    }
  }

  return largest;
}

static float average(int a[], int n) {
  int total = 0;

  for (int i = 0; i < n; i++) {
    total += a[i];
  }

  return (float)total / n;
}

static int num_positive(int a[], int n) {
  int count = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      count++;
    }
  }

  return count;
}

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  int a[5] = {1, 7, 11, 3, -3};

  printf("largest_element(a, n) returns %d\n", largest_element(a, ARRAY_COUNT(a)));
  printf("average(a, n) returns %f\n", (double)average(a, ARRAY_COUNT(a)));
  printf("num_positive(a, n) returns %d\n", num_positive(a, ARRAY_COUNT(a)));

  return 0;
}
