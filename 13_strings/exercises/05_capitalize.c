#include <stdio.h>
#include <ctype.h>

static void capitalize(char *string) {
  while (*string) {
    *string = (char)toupper(*string);
    string++;
  }
}

int main(void) {
  char string[] = "Hello 123";
  capitalize(string);
  printf("%s\n", string);
  return 0;
}
