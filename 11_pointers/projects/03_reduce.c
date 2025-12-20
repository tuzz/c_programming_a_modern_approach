#include <stdio.h>
#include <stdbool.h>

static void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {
  int m = numerator;
  int n = denominator;

  while (true) {
    if (n == 0) { break; }

    int remainder = m % n;
    m = n;
    n = remainder;
  }

  *reduced_numerator = numerator / m;
  *reduced_denominator = denominator / m;
}

int main(void) {
  int numerator, denominator;
  printf("Enter a fraction: ");
  scanf("%d /%d", &numerator, &denominator);

  int reduced_numerator = 0;
  int reduced_denominator = 0;
  reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);

  printf("In lowest terms: %d/%d\n", reduced_numerator, reduced_denominator);
  return 0;
}
