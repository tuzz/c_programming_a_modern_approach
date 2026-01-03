#include <stdio.h>

#define MK_COLOR(red, green, blue) ((blue) << 16 | (green) << 8 | (red))
#define GET_RED(color) ((color) & LOWER_BYTE)
#define GET_GREEN(color) ((color) >> 8 & LOWER_BYTE)
#define GET_BLUE(color) ((color) >> 16 & LOWER_BYTE)
#define LOWER_BYTE 0xFF

int main(void) {
  long x = MK_COLOR(255, 100, 50);

  printf("red: %ld\n", GET_RED(x));
  printf("green: %ld\n", GET_GREEN(x));
  printf("blue: %ld\n", GET_BLUE(x));

  return 0;
}
