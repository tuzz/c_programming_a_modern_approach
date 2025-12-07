#include <stdio.h>

int main(void) {
  float x, y;
  int i;

  // When entering '12.3 45.6 789', scanf will:
  // - Read '12.3' as a float because ' ' cannot be part of a float.
  // - Read '45' as a decimal because '.' cannot be part of a decimal.
  // - Read '.6' as a float because ' ' cannot be part of a float.
  scanf("%f%d%f", &x, &i, &y);

  printf("%f\n", (double)x);
  printf("%d\n", i);
  printf("%f\n", (double)y);

  return 0;
}
