#include <stdio.h>

void swap(int a, int b);

int main(void) {
  int i = 1, j = 2;

  // Prints "i = 1, j = 2" because the variables i, j are copied by value into
  // the swap function and do not mutate i, j in the current function scope.
  swap(i, j);
  printf("i = %d, j = %d\n", i, j);
  return 0;
}

void swap(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
}
