#include <stdio.h>

int main(void) {
  int number;
  printf("Enter a two-digit number: ");
  scanf("%d", &number);

  int first_digit = number / 10;
  int last_digit = number % 10;

  printf("The reversal is: %d%d\n", last_digit, first_digit);

  return 0;
}
