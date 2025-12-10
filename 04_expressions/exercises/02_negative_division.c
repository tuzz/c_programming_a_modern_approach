#include <stdio.h>

int main(void) {
  int i = 5;
  int j = 3;

  // In C89, the compiler might round away from zero in which case the following
  // expressions would not have the same answer. In C99 they always will.

  printf("(-i) / j = %d\n", (-i) / j); // Could evaluate to -2 in C89.
  printf("-(i / j) = %d\n", -(i / j)); // Always evaluates to -1.

  return 0;
}
