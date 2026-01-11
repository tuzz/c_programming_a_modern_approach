#include <stdio.h>

int main(void) {
  // The conversion specifications are equivalent for positive integers:
  printf("%.4d\n", 123);
  printf("%04d\n", 123);
  printf("%.4d\n", 12345);
  printf("%04d\n", 12345);

  // The conversion specifications are NOT equivalent for negative integers:
  // - precision specifies minimum width for the magnitude of the number, excluding sign
  // - padding specifies minimum width for full expression to be printed, including sign
  printf("%.4d\n", -12);
  printf("%04d\n", -12);

  return 0;
}
