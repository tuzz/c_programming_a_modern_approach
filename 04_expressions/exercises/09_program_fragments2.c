#include <stdio.h>

int main(void) {
  int i, j, k;

  // a) Prints "63 8"
  i = 7; j = 8;
  i *= j + 1;
  printf("%d %d\n", i, j);

  // b) Prints "3 2 1"
  i = j = k = 1;
  i += j += k;
  printf("%d %d %d\n", i, j, k);

  // c) Prints "2 -1 3"
  i = 1; j = 2; k = 3;
  i -= j -= k;
  printf("%d %d %d\n", i, j, k);

  // d) Prints "0 0 0"
  i = 2; j = 1; k = 0;
  i *= j *= k;
  printf("%d %d %d\n", i, j, k);

  return 0;
}
