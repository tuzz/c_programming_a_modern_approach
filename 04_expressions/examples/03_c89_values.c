#include <stdio.h>

int main(void) {
  printf("%d\n", 8 / 5); // a) 1
  printf("%d\n", -8 / 5); // b) -1 or -2
  printf("%d\n", 8 / -5); // c) -1 or -2
  printf("%d\n", -8 / -5); // d) 1 or 2
  return 0;
}
