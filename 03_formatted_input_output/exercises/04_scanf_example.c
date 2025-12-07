#include <stdio.h>

int main(void) {
  int i, j;
  float x;

  // When entering '10.3 5 6', scanf will:
  // - Read '10' as a decimal because '.' cannot be part of a decimal.
  // - Read '.3' as a float because ' ' cannot be part of a float.
  // - Read '5' as a decimal because ' ' cannot be part of a decimal.
  scanf("%d%f%d", &i, &x, &j);

  printf("i: %d\n", i);
  printf("x: %f\n", (double)x);
  printf("j: %d\n", j);

  return 0;
}
