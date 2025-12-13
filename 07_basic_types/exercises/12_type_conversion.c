#include <stdio.h>

int main(void) {
  int i = 0;
  float f = 0.0f;
  double d;

  // First i + f is evaluated which implicitly converts i to a float. The result
  // of the addition is float which is then implicitly cast to a double.
  d = i + f;
  printf("%f\n", d);

  return 0;
}
