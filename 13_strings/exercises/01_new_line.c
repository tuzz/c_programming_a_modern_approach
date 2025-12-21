#include <stdio.h>

int main(void) {
  // a) correct
  printf("%c", '\n');

  // b) incorrect because a char * is provided when a char (int) is expected
  // printf("%c", "\n");

  // c) incorrect because a char is provided when a char * is expected
  // printf("%s", '\n');

  // d) correct
  printf("%s", "\n");

  // e) incorrect because a char is provided when a char * is expected
  // printf('\n');

  // f) correct
  printf("\n");

  // g) correct
  putchar('\n');

  // h) incorrect because a char * is provided when a char (int) is expected
  // putchar("\n");

  // i) incorrect because a char is provided when a char * is expected
  // puts('\n');

  // j) incorrect because puts already includes a newline so two are printed
  puts("\n");

  // k) correct
  puts("");

  return 0;
}
