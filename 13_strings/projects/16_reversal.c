#include <stdio.h>
#include <string.h>

static void reverse(char *message) {
  int length = (int)strlen(message);
  if (length <= 1) { return; }

  char *m = message;
  char *r = message + length - 1;

  while (m < r) {
    char tmp = *m;
    *m = *r;
    *r = tmp;
    m++;
    r--;
  }
}

int main(void) {
  printf("Enter a message: ");
  char message[50] = "", c, *p = message;

  while ((c = (char)getchar()) != '\n' && p < &message[50]) {
    *p++ = c;
  }

  reverse(message);
  printf("Reversal is: %s\n", message);

  return 0;
}
