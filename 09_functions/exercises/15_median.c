#include <stdio.h>

static double median(double x, double y, double z) {
  double tmp;

  // Sort x and y.
  if (y < x) {
    tmp = x;
    x = y;
    y = tmp;
  }

  // Sort y and z.
  if (z < y) {
    tmp = y;
    y = z;
    z = tmp;
  }

  return y;
}

int main(void) {
  printf("median(1, 2, 3) returns %f\n", median(1, 2, 3));
  printf("median(2, 1, 3) returns %f\n", median(2, 1, 3));
  printf("median(3, 1, 2) returns %f\n", median(3, 1, 2));
  return 0;
}
