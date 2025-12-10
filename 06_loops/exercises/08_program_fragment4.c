#include <stdio.h>

int main(void) {
  int i, count = 0;

  // Prints "10 5 3 2 1 1 1 ..."
  for (i = 10; i >= 1; i /= 2) {
    printf("%d ", i++);

    count += 1;
    if (count >= 10) {
      break;
    }
  }

  // i=10, i=11
  // i=5, i=6
  // i=3, i=4
  // i=2, i=3
  // i=1, i=2
  // i=1, i=2
  // i=1, i=2
  // ...

  return 0;
}
