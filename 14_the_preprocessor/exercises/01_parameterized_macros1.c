#include <stdio.h>

#define CUBE(x) ((x) * (x) * (x))
#define REMAINDER4(n) ((n) % 4)
#define PRODUCT_LESS_THAN_100(x, y) ((x) * (y) < 100)

int main(void) {
  printf("%d\n", CUBE(1 + 2));
  printf("%d\n", CUBE(3 + 4));

  printf("%d\n", REMAINDER4(1 + 2));
  printf("%d\n", REMAINDER4(5 + 5));

  printf("%d\n", PRODUCT_LESS_THAN_100(33, 3));
  printf("%d\n", PRODUCT_LESS_THAN_100(34, 3));

  return 0;
}
