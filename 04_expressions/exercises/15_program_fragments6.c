#include <stdio.h>

int main(void) {
  int i, j;

  // Prints "3 2"
  i = 1; j = 2;
  i += j;
  printf("%d %d\n", i, j);

  // Prints "0 2"
  i = 1; j = 2;
  i--;
  printf("%d %d\n", i, j);

  // Prints "1 2"
  i = 1; j = 2;
  i * j / i;
  printf("%d %d\n", i, j);

  // Prints "1 3"
  i = 1; j = 2;
  i % ++j;
  printf("%d %d\n", i, j);

  return 0;
}
