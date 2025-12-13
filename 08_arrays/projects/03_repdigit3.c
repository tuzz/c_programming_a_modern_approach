#include <stdbool.h>
#include <stdio.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  bool digit_seen[10];
  int digit;
  long n;

  while (true) {
    for (size_t i = 0; i < ARRAY_COUNT(digit_seen); i++) {
      digit_seen[i] = false;
    }

    printf("Enter a number: ");
    scanf("%ld", &n);
    if (n <= 0) { break; }

    while (n > 0) {
      digit = n % 10;
      if (digit_seen[digit])
        break;
      digit_seen[digit] = true;
      n /= 10;
    }

    if (n > 0)
      printf("Repeated digit\n");
    else
      printf("No repeated digit\n");
  }

  return 0;
}
