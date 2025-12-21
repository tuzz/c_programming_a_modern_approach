#include <stdio.h>

int main(void) {
  char *p = "abc";

  // a) illegal because a char * is provided when a char (int) is expected
  // putchar(p);

  // b) legal, prints "a"
  putchar(*p);

  // c) legal, prints "abc\n"
  puts(p);

  // d) illegal because a char is provided when a char * is expected
  // puts(*p);
}
