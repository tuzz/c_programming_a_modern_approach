#include <stdio.h>

int main(void) {
  // "%d" and " %d" are equivalent because a space character in a scanf string
  // matches any amount of whitespace, including none.

  // "%d-%d-%d" and "%d -%d -%d" are not equivalent when ordinary characters are
  // used in scanf strings, an exact match occurs. Since '-' is not whitespace,
  // it means that '1 - 2 - 3' would not match the first pattern.
  //                 ^ no match here
  int x, y, z;
  scanf("%d-%d-%d", &x, &y, &z);
  printf("x: %d\n", x);
  printf("y: %d\n", y);
  printf("z: %d\n", z);

  // "%f" and "%f " are not equivalent because the trailing whitesace matches
  // any amount of whitespace, so scanf will keep reading input until a
  // non-whitespace character occurs which can result in the program hanging.

  // "%f,%f" and "%f, %f" are equivalent because conversion specifiers maybe
  // be preceded by any amount of whitespace, including none, so the additional
  // space makes no difference to how the patterns will be matched.

  return 0;
}
