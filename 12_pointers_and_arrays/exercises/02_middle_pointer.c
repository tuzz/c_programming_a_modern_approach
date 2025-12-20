#include <stdio.h>

int main(void) {
  int a[5] = {1, 2, 3, 4, 5};
  int *low = &a[0];
  int *high = &a[4];

  // The following statement is illegal because it attempts to add two pointers
  // together. The only allowed operations are:
  // 1) pointer + integer
  // 2) pointer - integer
  // 3) pointer - pointer
  // int *middle = (low + high) / 2;

  // Therefore, to fix it, we could subtract the pointers instead:
  int *middle = low + (high - low) / 2;
  printf("%d\n", *middle);

  return 0;
}
