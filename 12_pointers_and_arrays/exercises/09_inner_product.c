#include <stdio.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

static double inner_product(const double *a, const double *b, int n) {
  double sum = 0.0;

  for (const double *p = a, *q = b; p < &a[n]; p++, q++) {
    sum += *p * *q;
  }

  return sum;
}

int main(void) {
  double a[3] = {1.0, 2.0, 3.0};
  double b[3] = {4.0, 5.0, 6.0};

  double sum = inner_product(a, b, ARRAY_COUNT(a));
  printf("sum: %f\n", sum);

  return 0;
}
