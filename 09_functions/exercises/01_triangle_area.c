#include <stdio.h>

static double triangle_area(double base, double height) { // Must have a type per parameter.
  double product = base * height; // Must be declared inside the function.
  return product / 2;
}

int main(void) {
  printf("The area of the triangle is %f\n", triangle_area(3, 5));
  return 0;
}
