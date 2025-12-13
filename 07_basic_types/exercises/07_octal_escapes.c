#include <stdio.h>

int main(void) {
  // a) \10
  char a1 = '\b'; // ASCII: 8 (decimal)
  char a2 = '\10';
  printf("a) %s\n", a1 == a2 ? "correct" : "incorrect");

  // b) \12
  char b1 = '\n'; // ASCII: 10 (decimal)
  char b2 = '\12';
  printf("b) %s\n", b1 == b2 ? "correct" : "incorrect");

  // c) \15
  char c1 = '\r'; // ASCII: 13 (decimal)
  char c2 = '\15';
  printf("c) %s\n", c1 == c2 ? "correct" : "incorrect");

  // d) \11
  char d1 = '\t'; // ASCII: 9 (decimal)
  char d2 = '\11';
  printf("d) %s\n", d1 == d2 ? "correct" : "incorrect");

  return 0;
}
