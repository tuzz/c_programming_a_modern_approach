#include <stdio.h>

int main(void) {
  int n = 16;

  if (n % 2 == 0) {           // <-- The loop mistakenly had an empty statement.
    printf("n is even\n");
  }

  return 0;
}
