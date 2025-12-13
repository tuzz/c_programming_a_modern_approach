#include <stdio.h>

int main(void) {
  int array[10] = {0};

  printf("%lu\n", sizeof(array) / sizeof(array[0]));

  // This technique is inferior to the one above because the count would become
  // incorrect if the type of elements in the array changed was changed later.
  printf("%lu\n", sizeof(array) / (sizeof(char)));

  return 0;
}
