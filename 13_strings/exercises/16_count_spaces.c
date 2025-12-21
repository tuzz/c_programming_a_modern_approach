#include <stdio.h>

static int count_spaces(const char *s) {
  int count = 0;

  for (; *s != '\0'; s++)
    if (*s == ' ')
      count++;
  return count;
}

int main(void) {
  printf("%d\n", count_spaces("hello world"));
  printf("%d\n", count_spaces(" hello world "));
  return 0;
}
