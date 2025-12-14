#include <stdio.h>

static double median(double x, double y, double z) {
  if (x <= y) {
    if (y <= z) { return y; }
    else if (x <= z) { return z; }
    else { return x; }
  }

  if (z <= y) { return y; }
  if (x <= z) { return x; }
  return z;
}

int main(void) {
  printf("median(1, 2, 3) returns %f\n", median(1, 2, 3));
  printf("median(2, 1, 3) returns %f\n", median(2, 1, 3));
  printf("median(3, 1, 2) returns %f\n", median(3, 1, 2));
  return 0;
}
