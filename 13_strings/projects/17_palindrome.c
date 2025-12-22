#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

static bool is_palindrome(const char *message) {
  int length = (int)strlen(message);
  if (length <= 1) { return true; }

  const char *m = message;
  const char *r = message + length - 1;

  while (m < r) {
    if (!isalpha(*m)) { m++; }
    if (!isalpha(*r)) { r--; }

    if (*m != *r) { return false; }

    m++;
    r--;
  }

  return true;
}

int main(void) {
  printf("Enter a message: ");
  char message[50] = "";
  fgets(message, 50, stdin);

  if (is_palindrome(message)) {
    printf("Palindrome\n");
  } else {
    printf("Not a palindrome\n");
  }

  return 0;
}
