#include <stdio.h>

int main(void) {
  int i = 0, *p = &i;

  // a) alias
  *p = 1;
  printf("i: %d\n", i);

  // b) not an alias
  // &p = 2;

  // c) not an alias
  // *&p = 3;

  // d) not an alias
  // &*p = 4;

  // e) not an alias
  // *i = 5;

  // f) not an alias
  // &i = 6;

  // g) alias
  *&i = 7;
  printf("i: %d\n", i);

  // h) not an alias
  // &*i = 8;

  return 0;
}
