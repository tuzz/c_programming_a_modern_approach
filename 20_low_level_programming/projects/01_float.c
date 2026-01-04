#include <stdio.h>

struct float_bits {
  unsigned int fraction: 23;
  unsigned int exponent: 8;
  unsigned int sign: 1;
};

union my_float {
  float f;
  struct float_bits b;
};

int main(void) {
  union my_float m;

  m.b.sign = 1;
  m.b.exponent = 128;
  m.b.fraction = 0;

  printf("%f\n", (double)m.f);

  return 0;
}
