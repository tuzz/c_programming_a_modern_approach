#include <stdio.h>

int main(void) {
  int i, count = 0;

  i = 10;
  while (i >= 1) {
    printf("%d ", i++);
    i /= 2;

    // Terminate after 10 iterations.
    count += 1;
    if (count >= 10) {
      break;
    }
  }
}
