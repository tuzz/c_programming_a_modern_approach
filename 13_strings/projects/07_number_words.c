#include <stdio.h>

int main(void) {
  char *tens_names[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "nintety"};
  char *teen_names[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  char *ones_names[] = {"", "-one", "-two", "-three", "-four", "-five", "-six", "-seven", "-eight", "-nine"};

  int number;
  printf("Enter a two-digit number: ");
  scanf("%d", &number);

  if (number < 10 || number > 99) {
    printf("Invalid two-digit number.\n");
    return 1;
  }

  int tens = number / 10;
  int ones = number % 10;
  printf("You entered the number ");
  printf("%s", tens_names[tens]);

  if (tens == 1) {
    printf("%s", teen_names[ones]);
  } else {
    printf("%s", ones_names[ones]);
  }

  printf(".\n");
  return 0;
}
