#include <stdio.h>

int main(void) {
  // a) is legal
  short unsigned int a = 1;

  // b) is not legal
  // short float b;

  // c) is legal
  long double c = 1.0;

  // d) is legal
  unsigned long d = 1;

  return 0;
}
