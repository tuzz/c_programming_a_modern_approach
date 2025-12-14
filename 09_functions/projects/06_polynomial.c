#include <stdio.h>

static double compute_polynomial(double x) {
  double x2 = x * x;
  double x3 = x * x2;
  double x4 = x * x3;
  double x5 = x * x4;

  return 3 * x5 + 2 * x4 - 5 * x3 - x2 + 7 * x - 6;
}

int main(void) {
  double x;
  printf("Enter x: ");
  scanf("%lf", &x);

  printf("f(x) is %f\n", compute_polynomial(x));
  return 0;
}
