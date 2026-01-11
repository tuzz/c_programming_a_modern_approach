#include <stdio.h>

int main(void) {
  int n, i, j;
  float x;

  n = scanf("%d%f%d", &i, &x, &j);
  printf("i: %d, j: %d, n: %d, x: %f\n", i, j, n, (double)x);

  // a) "10 20 30\n" will set i=10, j=30, n=3, x=20.0, consumed: "10 20 30"
  // b) "1.0 2.0 3.0\n" will set i=1, j=2, n=3 x=0.0, consumed: "1.0 2"
  // c) "0.1 0.2 0.3\n" will set i=0, j=0, n=3, x=0.1, consumed: "0.1 0"
  // d) ".1 .2 .3\n" will set n=0, consumed nothing.

  return 0;
}
