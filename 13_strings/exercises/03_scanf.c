#include <stdio.h>

int main(void) {
  int i, j;
  char s[50];

  scanf("%d%s%d", &i, s, &j);

  // If the user enters "12abc34 56def78" then
  // - i will be set to 12
  // - s will be set to "abc34"
  // - j will be set to 56

  printf("i: %d\n", i);
  printf("s: %s\n", s);
  printf("j: %d\n", j);

  return 0;
}
