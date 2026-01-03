#include <stdio.h>

int main(void) {
  unsigned short i, j, k;

  // Order of precedence: ~ [* / %] [+ -] [<< >>] & ^ | [== !=] && ||

  // a) Prints "0"
  i = 8; j = 9;
  printf("%d\n", i >> (1 + j) >> 1);
  // i >> (1 + j) >> 1
  // i >> 10 >> 1
  // i >> 11

  // b) Prints "0"
  i = 1;
  printf("%d\n", i & ~i);

  // c) Prints "1"
  i = 2; j = 1; k = 0;
  printf("%d\n", (~i & j) ^ k);
  // (~i & j) ^ k
  // 1 ^ k

  // d) Prints "15"
  i = 7; j = 8; k = 9;
  printf("%d\n", i ^ (j & k));
  // i ^ (j & k)
  // i ^ 8

  return 0;
}
