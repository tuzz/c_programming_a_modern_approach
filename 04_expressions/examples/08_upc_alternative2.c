#include <stdio.h>

int main(void) {
  int total = 10;

  // Yes, the algorithms would be equvalent.
  int original = 9 - (total - 1) % 10;
  printf("original: %d\n", original);

  int alternative = (10 - (total % 10)) % 10;
  printf("alternative: %d\n", alternative);

  return 0;
}
