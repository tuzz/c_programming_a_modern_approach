#include <stdio.h>

static int read_line(char str[], int n) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n' && ch != EOF) {
    if (i < n) {
      str[i++] = (char)ch;
    }
  }
  str[i] = '\0';
  return i;
}

int main(void) {
  char str[50];
  read_line(str, 50);

  printf("str: %s\n", str);
  return 0;
}
