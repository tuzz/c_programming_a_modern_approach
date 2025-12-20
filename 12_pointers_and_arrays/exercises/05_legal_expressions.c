#include <stdio.h>

int main(void) {
  int a[5] = {1, 2, 3, 4, 5}, *p = a;

  // a) illegal
  // p == a[0];

  // b) legal, true
  printf("%s\n", p == &a[0] ? "true" : "false");

  // c) legal, true
  printf("%s\n", *p == a[0] ? "true" : "false");

  // d) legal, true
  printf("%s\n", p[0] == a[0] ? "true" : "false");

  return 0;
}
