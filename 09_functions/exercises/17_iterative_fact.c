#include <stdio.h>

static int fact(int n) {
  int product = 1;

  for (int i = 2; i <= n; i++) {
    product *= i;
  }

  return product;
}

int main(void) {
  printf("fact(0) returns %d\n", fact(0));
  printf("fact(1) returns %d\n", fact(1));
  printf("fact(2) returns %d\n", fact(2));
  printf("fact(3) returns %d\n", fact(3));
  printf("fact(4) returns %d\n", fact(4));
  return 0;
}
