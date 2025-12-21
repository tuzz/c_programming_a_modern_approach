#include <stdio.h>
#include <ctype.h>

static int read_line(char str[], int n) {
  int ch, i = 0;

  // Skip leading whitespace.
  while (isspace((ch = getchar())) && ch != EOF) {}

  do {
    // Leave behind characters that we don't have room to store (reserve space for \0).
    if (i < n - 1) {
      str[i++] = (char)ch;

      // Stop reading at the first new-line character (stored in the string).
      if (ch == '\n') { break; }
    } else {
      break;
    }
  } while ((ch = getchar()) != EOF);

  str[i] = '\0';
  return i;
}

int main(void) {
  char str[10];
  read_line(str, 10);

  printf("str: %s", str);
  return 0;
}
