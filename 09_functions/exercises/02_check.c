#include <stdio.h>

static int check(int x, int y, int n) {
  return (x >= 0 && x < n && y >= 0 && y < n) ? 1 : 0;
}

int main(void) {
  printf("check(1, 2, 3) returns %d\n", check(1, 2, 3));
  printf("check(3, 2, 1) returns %d\n", check(3, 2, 1));
  printf("check(1, 3, 2) returns %d\n", check(1, 3, 2));
  return 0;
}
