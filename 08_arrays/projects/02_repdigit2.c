#include <stdbool.h>
#include <stdio.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  int digit_count[10] = {0};
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    digit_count[digit]++;
    n /= 10;
  }

  printf("Digit:       ");
  for (size_t i = 0; i < ARRAY_COUNT(digit_count); i++) {
    printf("%zu ", i);
  }
  putchar('\n');

  printf("Occurrences: ");
  for (size_t i = 0; i < sizeof(digit_count) / sizeof(digit_count[0]); i++) {
    printf("%d ", digit_count[i]);
  }
  putchar('\n');

  return 0;
}
