#include <stdio.h>

static int digit(int n, int k) {
  for (int i = 1; i < k; i++) { n /= 10; }
  return n % 10;
}

int main(void) {
  printf("digit(829, 1) returns %d\n", digit(829, 1));
  printf("digit(829, 2) returns %d\n", digit(829, 2));
  printf("digit(829, 3) returns %d\n", digit(829, 3));
  printf("digit(829, 4) returns %d\n", digit(829, 4));
  printf("digit(829, 5) returns %d\n", digit(829, 5));
  return 0;
}
