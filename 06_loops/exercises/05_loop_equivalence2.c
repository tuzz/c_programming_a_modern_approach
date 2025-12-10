#include <stdio.h>

int main(void) {
  int i;

  i = 10;
  while (i < 10) {
    printf("First loop: %d\n", i);
    i++;
  }

  i = 10;
  for (; i < 10;) {
    printf("Second loop: %d\n", i);
    i++;
  }

  // Loop (c) is not equivalent to (a) and (b). In this loop, the statement runs
  // one additional time first regardless of whether the loop condition is met.
  i = 10;
  do {
    printf("Third loop: %d\n", i);
    i++;
  } while (i < 10);

  return 0;
}
