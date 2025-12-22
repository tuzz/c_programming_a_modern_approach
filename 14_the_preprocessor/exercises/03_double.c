#include <stdio.h>

#define DOUBLE(x) 2*x
#define DOUBLE_FIXED(x) (2 * (x))

int main(void) {
  // a) The macro expands to 2*1+2 so the value is 4.
  printf("%d\n", DOUBLE(1+2));

  // b) The macro expands to 4/2*2 so the value is 4.
  printf("%d\n", 4/DOUBLE(2));

  // c) Prints "6" and "1" as you would expect.
  printf("%d\n", DOUBLE_FIXED(1 + 2));
  printf("%d\n", 4 / DOUBLE_FIXED(2));

  return 0;
}
