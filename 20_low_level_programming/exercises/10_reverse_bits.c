#include <stdio.h>
#include <limits.h>

#define NUM_BITS_UNSIGNED_INT ((int)sizeof(unsigned int) * CHAR_BIT)

unsigned int reverse_bits(unsigned int n) {
  unsigned int reversed = 0;

  for (int i = 0; i < NUM_BITS_UNSIGNED_INT; i++) {
    reversed <<= 1;
    reversed |= n & 1;
    n >>= 1;
  }

  return reversed;
}

int main(void) {
  printf("123 reversed is %u\n", reverse_bits(123));
  printf("3724541952 reversed is %u\n", reverse_bits(3724541952));

  return 0;
}
