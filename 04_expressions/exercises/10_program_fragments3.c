#include <stdio.h>

int main(void) {
  int i, j;

  // a) Prints "12 12"
  i = 6;
  j = i += i;
  printf("%d %d\n", i, j);

  // b) Prints "3 4"
  i = 5;
  j = (i -= 2) + 1;
  printf("%d %d\n", i, j);

  // c) Prints "2 8"
  i = 7;
  j = 6 + (i = (int)2.5);
  printf("%d %d\n", i, j);

  // d) Undefined behaviour: probably prints "6 9" or "6 3"
  i = 2; j = 8;
  j = (i = 6) + (j = 3);
  printf("%d %d\n", i, j);

  return 0;
}
