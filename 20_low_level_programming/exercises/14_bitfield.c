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

void print_bits(unsigned int n, int num_bits) {
  for (int i = num_bits - 1; i >= 0; i--) {
    printf("%s", n & 1 << i ? "1" : "0");
  }
  printf("\n");
}

int main(void) {
  union my_float m = { .f = -123.45f };

  printf("sign = %d = ", m.b.sign);
  print_bits(m.b.sign, 1);

  printf("exponent = %d = ", m.b.exponent);
  print_bits(m.b.exponent, 8);

  printf("fraction = %d = ", m.b.fraction);
  print_bits(m.b.fraction, 23);

  return 0;
}
