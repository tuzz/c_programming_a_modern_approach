#include <stdio.h>

int main(void) {
  int i, j, k;

  // a) Prints "1 2"
  i = 5; j = 3;
  printf("%d %d\n", i / j, i % j);

  // b) Prints "0"
  i = 2; j = 3;
  printf("%d\n", (i + 10) % j);

  // c) Prints "1"
  i = 7; j = 8; k = 9;
  printf("%d\n", (i + 10) % k / j);

  // d) Prints "0"
  i = 1; j = 2; k = 3;
  printf("%d\n", (i + 5) % (j + 2) / k);

  return 0;
}
