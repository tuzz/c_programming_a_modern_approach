#include <stdio.h>

int main(void) {
  printf("Enter a message: ");
  char message[50], c, *p = message;

  while ((c = (char)getchar()) != '\n' && p < &message[50]) {
    *p = c;
    p++;
  }

  printf("Reversal is: ");
  for (p--; p >= message; p--) {
    printf("%c", *p);
  }
  printf("\n");

  return 0;
}
