#include <stdio.h>

unsigned int f(unsigned int i, int m, int n) {
  return (i >> (m + 1 - n)) & ~(~(unsigned int)0 << n);
}

int main(void) {
  // a) The expression ~(~0 << n) sets all bits to 1 then shifts left by n which
  // shifts zeros into the rightmost bits. It then performs unary negation
  // (again) which results in a number that is 000...11111 with n ones in the
  // least-significant bits. Therefore, this expression is equal to 2^n - 1.
  printf("%u\n", ~(~(unsigned int)0 << 5));

  // b) The function extracts n bits from i starting from bit m. It returns an
  // integer with the bits right-aligned in the least-significant bits.
  printf("%u\n", f(~(unsigned int)0, 3, 8));

  return 0;
}
