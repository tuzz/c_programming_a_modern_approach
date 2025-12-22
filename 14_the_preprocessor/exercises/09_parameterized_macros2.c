#include <stdio.h>

#define CHECK(x, y, n) ((x) >= 0 && (x) < (n) && (y) >= 0 && (y) < (n))

#define MEDIAN(x, y, z) ((x) < (y) ?          \
  ((x) > (z) ? (x) : (y) < (z) ? (y) : (z)) : \
  ((x) < (z) ? (x) : (y) > (z) ? (y) : (z)))

#define POLYNOMIAL(x) (3*((x)*(x)*(x)*(x)*(x)) + 2*((x)*(x)*(x)*(x)) - 5*(x)*(x)*(x) - (x)*(x) + 7*(x) - 6)

int main(void) {
  printf("%d\n", CHECK(1, 2, 3));
  printf("%d\n", CHECK(1, 2, 2));
  printf("\n");
  printf("%d\n", MEDIAN(1, 2, 3));
  printf("%d\n", MEDIAN(2, 1, 3));
  printf("%d\n", MEDIAN(3, 2, 1));
  printf("\n");
  printf("%d\n", MEDIAN(1, 1, 2));
  printf("%d\n", MEDIAN(2, 1, 2));
  printf("\n");
  printf("%d\n", POLYNOMIAL(1 + 1));

  return 0;
}
