#include <stdio.h>

int main(void) {
  unsigned short x = 0;

  // You can toggle a bit with: x ^= 1 << INDEX.
  // If the bit was 0 then xor will make it 1.
  // If the bit was 1 then xor will make it 0.

  x ^= 1 << 0;
  printf("%d\n", x);

  x ^= 1 << 1;
  printf("%d\n", x);

  x ^= 1 << 2;
  printf("%d\n", x);

  x ^= 1 << 3;
  printf("%d\n", x);

  x ^= 1 << 0;
  printf("%d\n", x);

  x ^= 1 << 1;
  printf("%d\n", x);

  x ^= 1 << 2;
  printf("%d\n", x);

  x ^= 1 << 3;
  printf("%d\n", x);

  return 0;
}
