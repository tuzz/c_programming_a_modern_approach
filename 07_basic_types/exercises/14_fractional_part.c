#include <stdio.h>

int main(void) {
  float f = 999999999999999999.123f;
  float fract_part;

  // The following expression does not always compute the fractional part
  // correctly because an integer might only hold 16 bits on older hardware and
  // one bit is for the sign. Therefore, the maximum value of an integer could
  // be 2^15 - 1 = 32,767. If the float holds a value larger than that then the
  // fractional part won't be correct.
  fract_part = f - (int) f;
  printf("%f does not equal 0.123\n", (double)fract_part);

  return 0;
}
