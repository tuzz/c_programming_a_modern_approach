#include <string.h>

int main(void) {
  char str[] = "hello";

  // a) sets index 0 to the null character.
  *str = 0;

  // b) sets index 0 to the null character.
  str[0] = '\0';

  // c) sets index 0 to the null character.
  strcpy(str, "");

  // d) is not equivalent because it concatenates an empty string on the end of
  // str rather than setting the first character of str to the null character.
  strcat(str, "");

  return 0;
}
