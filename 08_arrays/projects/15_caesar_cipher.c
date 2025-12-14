#include <stdio.h>

int main(void) {
  char message[80];
  char c;
  int i = 0;
  printf("Enter message to be encrypted: ");
  while ((c = (char)getchar()) != '\n') { message[i++] = c; }

  int n;
  printf("Enter shift amount (1-25): ");
  scanf("%d", &n);

  printf("Encrypted message: ");

  for (int j = 0; j < i; j++) {
    c = message[j];

    if (c >= 'A' && c <= 'Z') {
      putchar((c - 'A' + n) % 26 + 'A');
    } else if (c >= 'a' && c <= 'z') {
      putchar((c - 'a' + n) % 26 + 'a');
    } else {
      putchar(c);
    }
  }

  putchar('\n');
  return 0;
}
