#include <stdio.h>

int main(void) {
  int i, j;

  // Prints "5 4 3 2"
  for (i = 5, j = i - 1; (void)(i > 0), j > 0; --i, j = i - 1)
    printf("%d ", i);

  // i=5, j=4
  // i=4, j=3
  // i=3, j=2
  // i=2, j=1
  // i=1, j=0 <-- loop terminates because j=0

  return 0;
}
