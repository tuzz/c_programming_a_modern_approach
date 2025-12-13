#include <stdio.h>

int main(void) {
  long i, n;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%ld", &n);

  for (i = 1; i <= n; i++) {
    //printf("%10ld%10ld\n", i, i * i);

    if (i * i < 0) {
      printf("%ld\n", i);
      return 0;
    }
  }

  // int fails at 46341
  // This is because 46341^2 = 2,147,488,281 which exceeds 2^31 - 1.
  // My machine therefore uses 32 bits to represent a signed integer.

  // short fails at 182
  // This is because 182^2 = 33,124 which exceeds 2^15 - 1.
  // My machine therefore uses 16 bits to represent a signed short integer.

  // long fails at 3037000500
  // This is because 3037000500^2 = 9,223,372,037,000,250,000 which exceeds 2^63 - 1.
  // My machines therefore uses 64 bits to represent a signed long integer.

  return 0;
}
