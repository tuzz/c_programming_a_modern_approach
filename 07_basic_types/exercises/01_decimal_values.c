#include <stdio.h>

int main(void) {
  // a) Prints "63" which is (7 * 8^1) + (7 * 8^0)
  int a = 077;
  printf("%d\n", a);

  // b) Prints "119" which is (7 * 16^1) + (7 * 16^0)
  int b = 0x77;
  printf("%d\n", b);

  // c) Prints "2748" which is (10 * 16^2) + (11 * 16^1) + (12 * 16^0)
  int c = 0XABC;
  printf("%d\n", c);

  return 0;
}
