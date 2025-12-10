#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int numerator, denominator;
  printf("Enter a fraction: ");
  scanf("%d /%d", &numerator, &denominator);

  int m = numerator;
  int n = denominator;

  while (true) {
    if (n == 0) { break; }

    int remainder = m % n;
    m = n;
    n = remainder;
  }

  printf("In lowest terms: %d/%d\n", numerator / m, denominator / m);
  return 0;
}
