#include <stdio.h>

int main(void) {
  int total = 10;

  // In the original algorithm, if the total is a multiple of 10 then the
  // algorithm would evaluate to (10x - 1) % 10 = 9 and 9 - 9 equals 0.
  int original = 9 - (total - 1) % 10;
  printf("original: %d\n", original);

  // In the alternative algorithm, if the total is a multiple of 10 then the
  // algorithm would evaluate to 10x % 10 = 0 and 9 - 0 equals 9.
  int alternative = 10 - (total % 10);
  printf("alternative: %d\n", alternative);

  // Therefore, the algorithms are not equivalent for totals of the form 10x.

  return 0;
}
