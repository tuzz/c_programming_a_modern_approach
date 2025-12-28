#include <stdio.h>

static int order_by_value(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

int main(void) {
  int a[100];

  for (int i = 0; i < 100; i++) {
    a[i] = 100 - i;
  }

  qsort(&a[50], 50, sizeof(int), order_by_value);

  for (int i = 0; i < 100; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
