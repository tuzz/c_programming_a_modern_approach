#include <stdio.h>

int main(void) {
          // 0   1   2   3   4  5   6   7
  int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
  int *p = &a[1], *q = &a[5];

  // a) Prints "14"
  printf("%d\n", *(p + 3));

  // b) Prints "34"
  printf("%d\n", *(q - 3));

  // c) Prints "4"
  printf("%ld\n", q - p);

  // d) Prints "true"
  printf("%s\n", p < q ? "true" : "false");

  // e) Prints "false"
  printf("%s\n", *p < *q ? "true" : "false");

  return 0;
}
