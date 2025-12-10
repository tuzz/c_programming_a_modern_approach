#include <stdio.h>

int main(void) {
  int i, j, k;

  // a) Prints "1"
  i = 0; j = 5;
  printf("%d\n", (!i) < j);

  // b) Prints "1"
  i = 2; j = 1;
  printf("%d\n", !!i + !j);

  // c) Prints "1"
  i = 5; j = 0; k = -5;
  printf("%d\n", (i && j) || k);

  // d) Prints "1"
  i = 1; j = 2; k = 3;
  printf("%d\n", i < j || k);

  return 0;
}
