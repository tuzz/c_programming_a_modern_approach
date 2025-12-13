#include <stdio.h>

int main(void) {
  int i = 1;
  float f = 1.0f;
  double d = 1.0;

  // The type of the expression is double. First i * f will be evaluated which
  // implicitly converts i to a float. Then result / d will be evaluated which
  // implicitly converts result to a double and the result is double.
  printf("%f\n", i * f / d);

  return 0;
}
