#include <stdio.h>

int count_ones(unsigned char ch) {
  int ones = 0;

  ones += ch      & 1;
  ones += ch >> 1 & 1;
  ones += ch >> 2 & 1;
  ones += ch >> 3 & 1;
  ones += ch >> 4 & 1;
  ones += ch >> 5 & 1;
  ones += ch >> 6 & 1;
  ones += ch >> 7 & 1;

  return ones;
}

int main(void) {
  for (int i = 0; i < 256; i++) {
    printf("The number %d contains %d ones in binary.\n", i, count_ones((unsigned char)i));
  }

  return 0;
}
