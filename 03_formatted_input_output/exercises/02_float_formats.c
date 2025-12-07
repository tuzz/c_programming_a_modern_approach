#include <stdio.h>

int main(void) {
  float x = 123.456789f;

  printf("%-8.1e\n", (double)x);
  printf("%10.6e\n", (double)x);
  printf("%-8.3f\n", (double)x);
  printf("%6.0f\n", (double)x);

  return 0;
}
