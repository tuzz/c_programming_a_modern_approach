#include <stdio.h>

int main(void) {
  int i = 123;
  int j = 456;

  printf("%d\n", i < j ? -1 : i == j ? 0 : 1);

  // The answer in the book is (i > j) - (i < j) but I think it's better to
  // avoid using booleans as integers for better portability across languages.

  return 0;
}
