#include <stdio.h>

int main(void) {
  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int e = 5;

  // a * b - c * d + e
  // (a * b) - (c * d) + e
  // ((a * b) - (c * d)) + e
  // (((a * b) - (c * d))) + e
  // ((((a * b) - (c * d))) + e)
  printf("%d == ", a * b - c * d + e);
  printf("%d\n", ((((a * b) - (c * d))) + e));

  // a / b % c / d
  // (a / b) % c / d
  // ((a / b) % c) / d
  // (((a / b) % c) / d)
  printf("%d == ", a / b % c / d);
  printf("%d\n", (((a / b) % c) / d));

  // - a - b + c - + d
  // (- a) - b + c - (+ d)
  // ((- a) - b) + c - (+ d)
  // (((- a) - b) + c) - (+ d)
  // ((((- a) - b) + c) - (+ d))
  printf("%d == ", - a - b + c - + d);
  printf("%d\n", ((((- a) - b) + c) - (+ d)));

  // a * - b / c - d
  // a * (- b) / c - d
  // (a * (- b)) / c - d
  // ((a * (- b)) / c) - d
  // (((a * (- b)) / c) - d)
  printf("%d == ", a * - b / c - d);
  printf("%d\n", (((a * (- b)) / c) - d));

  return 0;
}
