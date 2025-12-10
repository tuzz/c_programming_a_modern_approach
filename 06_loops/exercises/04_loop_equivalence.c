#include <stdio.h>

int main(void) {
  int i;

  for (i = 0; i < 10; i++) {
    printf("First loop: %d\n", i);
  }

  for (i = 0; i < 10; ++i) {
    printf("Second loop: %d\n", i);
  }

  // Loop (c) is not equivalent to (a) and (b). In this loop, the variable i is
  // incremented immediate when first checking the loop condition. It will
  // therefore start counting from 1. Furthermore, because it post-increments,
  // the condition will be checked before increment, so it will print up to 10.
  for (i = 0; i++ < 10; ) {
    printf("Third loop: %d\n", i);
  }

  return 0;
}
