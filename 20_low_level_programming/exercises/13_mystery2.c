#include <stdio.h>
#include <limits.h>

#define NUM_BITS_UNSIGNED_INT ((int)sizeof(unsigned int) * CHAR_BIT)

void print_bits(unsigned int n) {
  for (int i = NUM_BITS_UNSIGNED_INT - 1; i >= 0; i--) {
    printf("%s", n & 1 << i ? "1" : "0");

    if (i % 8 == 0) {
      printf(" ");
    }
  }
  printf("\n");
}

int main(void) {
  unsigned int n = 123456789;

  while (n != 0) {
    print_bits(n);

    // The expression sets the rightmost 1 in the binary representation of the number to 0.
    n &= n - 1;
  }

  print_bits(n);
  return 0;
}
