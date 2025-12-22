#include <stdio.h>

#define NELEMS(a) (sizeof(a) / sizeof(a[0]))

int main(void) {
  int a[5] = {1, 2, 3, 4, 5};
  printf("%lu\n", NELEMS(a));
  return 0;
}
