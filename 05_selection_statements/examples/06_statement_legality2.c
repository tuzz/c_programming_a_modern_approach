#include <stdio.h>

int main(void) {
  int n = 5;

  // Yes, the following statement is legal:
  if (n == 1-10)
    printf("n is between 1 and 10\n");

  // But it evaluates n == -9 which is false when n is 5.
  // The programmer probably intended to write the following:
  if (n >= 1 && n <= 10) {
    printf("n is between 1 and 10\n");
  }
}
