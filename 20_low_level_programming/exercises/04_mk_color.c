#include <stdio.h>

#define MK_COLOR(red, green, blue) ((blue) << 16 | (green) << 8 | (red))

int main(void) {
  long x = MK_COLOR(255, 100, 50);

  for (int i = 31; i >= 0; i--) {
    printf("%s", x & 1 << i ? "1" : "0");

    if (i % 8 == 0) {
      printf(" ");
    }
  }
  printf("\n");

  return 0;
}
