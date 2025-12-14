#include <stdio.h>

static int fact(int n) {
  return n <= 1 ? 1 : n * fact(n - 1);
}

int main(void) {
  printf("fact(0) returns %d\n", fact(0));
  printf("fact(1) returns %d\n", fact(1));
  printf("fact(2) returns %d\n", fact(2));
  printf("fact(3) returns %d\n", fact(3));
  printf("fact(4) returns %d\n", fact(4));
  return 0;
}
