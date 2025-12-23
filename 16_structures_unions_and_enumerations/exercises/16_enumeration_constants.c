#include <stdio.h>

enum my_enum {
  FOO = 12345, // a) true
};

int main(void) {
  // b) false because enum constants are scoped to the file or block that they
  // were defined in whereas macros are global. For example:
  enum my_local_enum { BAR, BAZ };

  // c) true
  printf("%d\n", BAR);
  printf("%d\n", BAZ);

  // d) false because multiple names can have the same value, e.g.
  enum another_enum { A, B = 0, C = 0 };

  // e) true
  int sum = A + B + C;

  return 0;
}
