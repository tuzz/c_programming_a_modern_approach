#include <stdio.h>

// This macro swaps variables x and y without using additional memory.
// It can only be used with lvalues since it performs assignment.
#define M(x,y) ((x)^=(y),(y)^=(x),(x)^=(y))

int main(void) {
  int x = 3;
  int y = 13;

  M(x, y);
  printf("x=%d, y=%d\n", x, y);

  return 0;
}
