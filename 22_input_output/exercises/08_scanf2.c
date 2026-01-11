#include <stdio.h>

int main(void) {
  char ch;
  char str[10];

  scanf(" %c", &ch);
  scanf("%1s", str);

  // No, the two techniques are not equivalent because the %1s conversion
  // specifier will also read the null character into the string.

  return 0;
}
