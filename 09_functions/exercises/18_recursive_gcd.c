#include <stdio.h>

static int gcd(int m, int n) {
  return n == 0 ? m : gcd(n, m % n);
}

int main(void) {
  printf("gcd(3, 4) returns %d\n", gcd(3, 4));
  printf("gcd(3, 9) returns %d\n", gcd(3, 9));
  printf("gcd(8, 16) returns %d\n", gcd(8, 16));
  return 0;
}
