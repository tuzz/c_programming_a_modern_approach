#include <stdio.h>

int main(void) {
  int i = 0;
  long j = 0;
  unsigned int k = 0;

  // The type of the expression is unsigned int. First (int) j will be evaluated
  // which explicitly casts j which is a long to an int. Then j * k will be
  // evaluated which promotes j to an unsigned int. Then i + result will be
  // evaluated which promots i to an unsigned int and the result is unsigned int.
  printf("%d\n", i + (int) j * k);

  return 0;
}
