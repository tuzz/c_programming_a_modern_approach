#include <stdio.h>

int main(void) {
  int i, j;

  // a) Prints "6 16"
  i = 5;
  j = ++i * 3 - 2;
  printf("%d %d\n", i, j);

  // b) Prints "6 -7"
  i = 5;
  j = 3 - 2 * i++;
  printf("%d %d\n", i, j);

  // c) Prints "6 23"
  i = 7;
  j = 3 * i-- + 2;
  printf("%d %d\n", i, j);

  // d) Prints "6 15"
  i = 7;
  j = 3 + --i * 2;
  printf("%d %d\n", i, j);

  return 0;
}
