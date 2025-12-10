#include <stdio.h>

int main(void) {
  int number;
  printf("Enter a number: ");
  scanf("%d", &number);

  int num_digits =
    number >= -9   && number <= 9   ? 1 :
    number >= -99  && number <= 99  ? 2 :
    number >= -999 && number <= 999 ? 3 : 4;

  char* plural = num_digits > 1 ? "s" : "";
  printf("The number %d has %d digit%s\n", number, num_digits, plural);

  return 0;
}
