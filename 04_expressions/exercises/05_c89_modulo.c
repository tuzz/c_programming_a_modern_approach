#include <stdio.h>

int main(void) {
  // Note: (a / b) * b + a % b must equal a.

  printf("%d\n", 8 % 5); // a) 3 because 1 * 5 + answer = 8

  printf("%d\n", -8 % 5); // b) -3 because -1 * 5 + answer = -8
  printf("%d\n", -8 % 5); // b) 2 because -2 * 5 + answer = -8

  printf("%d\n", 8 % -5); // c) 3 because -1 * -5 + answer = 8
  printf("%d\n", 8 % -5); // c) -2 because -2 * -5 + answer = 8

  printf("%d\n", -8 % -5); // d) -3 because 1 * -5 + answer = -8
  printf("%d\n", -8 % -5); // d) -2 because 2 * -5 + answer = -8

  return 0;
}
