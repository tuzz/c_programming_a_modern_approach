#include <stdio.h>

unsigned short swap_bytes(unsigned short i) {
  return (unsigned short)(i << 8 | i >> 8);
}

int main(void) {
  unsigned short number;
  printf("Enter a hexadecimal number (up to four digits): ");
  scanf("%hx", &number);

  unsigned short swapped = swap_bytes(number);
  printf("Number with bytes swapped: %hx\n", swapped);

  return 0;
}
