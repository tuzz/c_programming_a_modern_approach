#include <stdio.h>

static void swap(int *p, int *q) {
  int tmp = *p;
  *p = *q;
  *q = tmp;
}

int main(void) {
  int x = 123;
  int y = 456;

  swap(&x, &y);

  printf("x: %d\n", x);
  printf("y: %d\n", y);

  return 0;
}
