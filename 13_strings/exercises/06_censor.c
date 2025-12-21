#include <stdio.h>
#include <string.h>

static void censor(char *string) {
  while (*string) {
    if (strncmp(string, "foo", 3) == 0) {
      strncpy(string, "xxx", 3);
      string += 3;
    } else {
      string++;
    }
  }
}

int main(void) {
  char string[] = "food fool";
  censor(string);
  printf("%s\n", string);
  return 0;
}
