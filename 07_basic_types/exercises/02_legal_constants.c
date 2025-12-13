#include <stdio.h>

int main(void) {
  // a) is a legal floating-point constant. The leading digit makes it look like
  // octal but that doesn't apply to floating-point numbers. In this case, the
  // value of the constant is a double equal to 10 * 10^2 which is 1000.0.
  double a = 010E2;
  printf("%f\n", a);

  // b) is a legal floating-point constant. It is a double with value 3210000.0.
  double b = 32.1E+5;
  printf("%f\n", b);

  // c) is an illegal integer constant because it starts with a leading zero so
  // should be interpreted as octal, but it contains a 9 which is invalid.
  // int c = 0790;
  // printf("%d\n", c);

  // d) is an illegal integer constant since it contains an underscore.
  // int d = 100_000;
  // printf("%d\n", d);

  // e) is a legal floating-point constant. It is a double with value 0.03978.
  double e = 3.978e-2;
  printf("%f\n", e);

  return 0;
}
