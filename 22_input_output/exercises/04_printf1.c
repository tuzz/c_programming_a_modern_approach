#include <stdio.h>

int main(void) {
  // a) Prints "00000083.736"
  printf("%#012.5g\n", 83.7361);

  // b) Prints "00000029749."
  printf("%#012.5g\n", 29748.6607);

  // c) Prints "001.0549e+09"
  printf("%#012.5g\n", 1054932234.0);

  // d) Prints "002.3522e-05"
  printf("%#012.5g\n", 0.0000235218);

  return 0;
}
