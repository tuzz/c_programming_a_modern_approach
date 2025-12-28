#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char *duplicate(const char *str) {
  char *new_str = malloc(strlen(str) + 1);
  if (new_str == NULL) { return NULL; }

  strcpy(new_str, str);
  return new_str;
}

int main(void) {
  char *str = "hello";

  char *new_str = duplicate(str);
  printf("%s\n", new_str);

  return 0;
}
