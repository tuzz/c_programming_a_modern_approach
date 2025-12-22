#include <stdio.h>

static void encrypt(char *message, int shift) {
  for (char *m = message; *m; m++) {
    if (*m >= 'A' && *m <= 'Z') {
      *m = (*m - 'A' + shift) % 26 + 'A';
    } else if (*m >= 'a' && *m <= 'z') {
      *m = (*m - 'a' + shift) % 26 + 'a';
    }
  }
}

int main(void) {
  char c, message[80] = "", *m = message;
  printf("Enter message to be encrypted: ");
  while ((c = (char)getchar()) != '\n') { *m++ = c; }

  int shift;
  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift);

  encrypt(message, shift);
  printf("Encrypted message: %s\n", message);
  return 0;
}
