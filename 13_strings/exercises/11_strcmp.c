#include <stdio.h>

static int strcmp(char *s, char *t) {
  int i;

  for (i = 0; s[i] == t[i]; i++) {
    if (s[i] == '\0') {
      return 0;
    }
  }
  return s[i] - t[i];
}

int main(void) {
  printf("%d\n", strcmp("abc", "abd"));
  printf("%d\n", strcmp("abc", "abc"));
  printf("%d\n", strcmp("abd", "abc"));
  return 0;
}
