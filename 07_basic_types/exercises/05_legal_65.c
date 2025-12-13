#include <stdio.h>

int main(void) {
  // a) is legal
  char a = 'A';
  printf("%c\n", a);

  // b) is not legal because you can't write integers in binary.
  // char b = 0b1000001;

  // c) is legal
  char c = 0101;
  printf("%c\n", c);

  // d) is legal
  char d = 0x41;
  printf("%c\n", d);

  return 0;
}
