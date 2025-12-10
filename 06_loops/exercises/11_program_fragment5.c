#include <stdio.h>

int main(void) {
  int sum, i;

  // Prints "20" which is the sum of even numbers less than 10.
  sum = 0;
  for (i = 0; i < 10; i++) {
    if (i % 2) // Evaluates to true for odd numbers.
      continue;
    sum += i;
  }
  printf("%d\n", sum);

  return 0;
}
