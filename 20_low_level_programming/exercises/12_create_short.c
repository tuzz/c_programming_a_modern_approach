#include <stdio.h>

unsigned short create_short(unsigned char high_byte, unsigned char low_byte) {
  // The fix is to add parentheses to the first part of the expression because
  // arithemetic operations have higher precedence than shifts.
  return (unsigned short)((high_byte << 8) + low_byte);
}

int main(void) {
  printf("%x\n", create_short(0x66, 0xff));
  return 0;
}
