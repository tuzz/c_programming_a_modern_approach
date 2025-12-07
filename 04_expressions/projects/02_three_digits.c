#include <stdio.h>

int main(void) {
  int number;
  printf("Enter a three-digit number: ");
  scanf("%d", &number);

  int first_digit = number / 100;
  int second_digit = (number % 100) / 10;
  int third_digit = number % 10;

  printf("The reversal is: %d%d%d\n", third_digit, second_digit, first_digit);

  return 0;
}
