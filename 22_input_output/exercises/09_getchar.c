#include <stdio.h>

int main(void) {
  // a) invalid, function doesn't exist.
  // getch();

  // b) valid
  getchar();

  // c) valid
  getc(stdin);

  // d) valid
  fgetc(stdin);

  return 0;
}
