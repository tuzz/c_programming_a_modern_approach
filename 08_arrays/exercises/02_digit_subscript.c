#include <stdio.h>

int main(void) {
  int array[5] = {1, 2, 3, 4, 5};
  char digit = '3';

  // Prints "4"
  printf("%d\n", array[digit - '0']);
}
