#include <stdio.h>
#include <math.h>

int main(void) {
  double x;
  printf("Enter a positive number: ");
  scanf("%lf", &x);

  double y = 1.0;
  double previous_y = 0.0;

  while (fabs(y - previous_y) > 0.00001 * y) {
    previous_y = y;
    y = (y + x / y) * 0.5;
  }

  printf("The square root is %.20f\n", y);
  return 0;
}
