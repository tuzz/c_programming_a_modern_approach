#include <stdio.h>

int main(void) {
  long fibonacci[40] = {0, 1};

  for (int i = 2; i < 40; i++) {
    fibonacci[i] = fibonacci[i - 2] + fibonacci[i - 1];
  }

  for (size_t i = 0; i < sizeof(fibonacci) / sizeof(fibonacci[0]); i++) {
    printf("fibonacci[%zu]: %ld\n", i, fibonacci[i]);
  }

  return 0;
}
