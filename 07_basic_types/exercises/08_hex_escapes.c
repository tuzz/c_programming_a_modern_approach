#include <stdio.h>

int main(void) {
  // a) \x8
  char a1 = '\b'; // ASCII: 8 (decimal)
  char a2 = '\x8';
  printf("a) %s\n", a1 == a2 ? "correct" : "incorrect");

  // b) \xa
  char b1 = '\n'; // ASCII: 10 (decimal)
  char b2 = '\xa';
  printf("b) %s\n", b1 == b2 ? "correct" : "incorrect");

  // c) \xd
  char c1 = '\r'; // ASCII: 13 (decimal)
  char c2 = '\xd';
  printf("c) %s\n", c1 == c2 ? "correct" : "incorrect");

  // d) \x9
  char d1 = '\t'; // ASCII: 9 (decimal)
  char d2 = '\x9';
  printf("d) %s\n", d1 == d2 ? "correct" : "incorrect");

  return 0;
}
