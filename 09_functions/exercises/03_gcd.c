#include <stdio.h>

static int gcd(int m, int n) {
  while (n != 0) {
    int remainder = m % n;
    m = n;
    n = remainder;
  }

  return m;
}

int main(void) {
  printf("gcd(3, 4) returns %d\n", gcd(3, 4));
  printf("gcd(3, 9) returns %d\n", gcd(3, 9));
  printf("gcd(8, 16) returns %d\n", gcd(8, 16));
  return 0;
}
