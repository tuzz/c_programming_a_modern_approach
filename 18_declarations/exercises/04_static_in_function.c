#include <stdio.h>

static int f(int i) {
  static int j = 0;
  return i * j++;
}

int main(void) {
  // Prints "0"
  printf("%d\n", f(10));

  // Call 4 more times.
  f(10);
  f(10);
  f(10);
  f(10);

  // Prints "50" because j was incremented 5 times previously and has static
  // storage so does not reset each time the function is called.
  printf("%d\n", f(10));

  return 0;
}
