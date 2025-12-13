#include <stdio.h>

int main(void) {
  char c = ' '; // ASCII: 32 is ' '

  // a) is legal
  int i = 0;
  i += c;
  printf("%d\n", i);

  // b) is legal
  c = 2 * c - 1;
  printf("%c\n", c); // ASCII: 63 is '?'

  // c) is legal
  putchar(c);
  putchar('\n');

  // d) is not legal because printf takes a char* not a char.
  // printf(c);

  return 0;
}
