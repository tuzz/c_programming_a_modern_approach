#include <stdio.h>

static double inner_product(double a[], double b[], int n) {
  double total = 0.0;

  for (int i = 0; i < n; i++) {
    total += a[i] * b[i];
  }

  return total;
}

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  double a[] = { 1.0, 2.0, 3.0 };
  double b[] = { 3.0, -4.0, 5.0 };

  printf("inner product: %f\n", inner_product(a, b, ARRAY_COUNT(a)));

  return 0;
}
