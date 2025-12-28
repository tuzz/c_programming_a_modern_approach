#include <stdio.h>
#include <stdlib.h>

static void *my_malloc(unsigned long size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("ERROR: malloc returned a null pointer\n");
    exit(1);
  }

  return ptr;
}

int main(void) {
  int *x = my_malloc(sizeof(*x));
  *x = 123;
  printf("%d\n", *x);

  int *y = my_malloc(999999999999999);
  *y = 123;
  printf("%d\n", *y);

  return 0;
}
