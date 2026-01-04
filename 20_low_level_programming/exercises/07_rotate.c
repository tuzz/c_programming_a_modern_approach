#include <stdio.h>
#include <limits.h>

#define NUM_BITS_UNSIGNED_INT ((int)sizeof(unsigned int) * CHAR_BIT)

unsigned int rotate_left(unsigned int i, int n) {
  n %= NUM_BITS_UNSIGNED_INT;
  if (n < 0) { n += NUM_BITS_UNSIGNED_INT; }

  return i << n | i >> (NUM_BITS_UNSIGNED_INT - n);
}

unsigned int rotate_right(unsigned int i, int n) {
  n %= NUM_BITS_UNSIGNED_INT;
  if (n < 0) { n += NUM_BITS_UNSIGNED_INT; }

  return i >> n | i << (NUM_BITS_UNSIGNED_INT - n);
}

int main(void) {
  unsigned int number;
  printf("Enter a hexadecimal number (up to 8 digits): ");
  scanf("%x", &number);

  int n;
  printf("Enter rotate amount: ");
  scanf("%d", &n);

  printf("Rotated left: %x\n", rotate_left(number, n));
  printf("Rotated right: %x\n", rotate_right(number, n));

  return 0;
}
