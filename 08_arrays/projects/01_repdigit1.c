#include <stdbool.h>
#include <stdio.h>

int main(void) {
  bool digit_seen[10] = {false};
  bool repeated[10] = {false};
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    if (digit_seen[digit]) {
      repeated[digit] = true;
    }
    digit_seen[digit] = true;
    n /= 10;
  }

  printf("Repeated digit(s): ");
  for (size_t i = 0; i < sizeof(repeated) / sizeof(repeated[0]); i++) {
    if (repeated[i]) {
      printf("%c ", (char)i + '0');
    }
  }
  putchar('\n');

  return 0;
}
