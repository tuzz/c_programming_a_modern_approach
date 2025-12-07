#include <stdio.h>

int main(void) {
  int i = 3;
  printf("i++ equals %d\n", i++);

  // ++i and (i += 1) are equivalent since an assignment returns the value after
  // the operation has been applied, i.e. the operation is applied first.
  i = 3;
  printf("++i equals %d\n", ++i);

  i = 3;
  printf("i += 1 equals %d\n", i += 1);

  return 0;
}
