#include <stdio.h>

int main(void) {
  int remainder;
  printf("Enter a number between 0 a 32767: ");
  scanf("%d", &remainder);

  int fifth_digit = remainder % 8;
  remainder /= 8;
  int fourth_digit = remainder % 8;
  remainder /= 8;
  int third_digit = remainder % 8;
  remainder /= 8;
  int second_digit = remainder % 8;
  remainder /= 8;
  int first_digit = remainder % 8;

  printf("In octal, your number is: %d%d%d%d%d\n", first_digit, second_digit, third_digit, fourth_digit, fifth_digit);
  return 0;
}
