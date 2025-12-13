#include <stdio.h>

int main(void) {
  char c = '\1';
  short s = 2;
  int i = -3;
  long m = 5;
  float f = 6.5f;
  double d = 7.5;

  // a) -2 int
  printf("%d\n", c + i);

  // b) 7 long
  printf("%ld\n", s + m);

  // c) 6.5 float
  printf("%f\n", (double)(f / c));

  // d) 3.75 double
  printf("%f\n", d / s);

  // e) -1.0 double
  printf("%f\n", (double)f - d);

  // f) 6 int
  printf("%d\n", (int) f);

  return 0;
}
