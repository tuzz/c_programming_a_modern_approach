#include <stdio.h>

int main(void) {
  printf("Enter a message: ");
  char message[50], c, *p = message;

  while ((c = (char)getchar()) != '\n' && p < &message[50]) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      *p++ = c;
    }
  }

  for (char *q = message; q < p; q++) {
    if (*q != *--p) {
      printf("Not a palindrome\n");
      return 0;
    }
  }

  printf("Palindrome\n");
  return 0;
}
