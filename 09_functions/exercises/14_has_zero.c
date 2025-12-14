#include <stdio.h>
#include <stdbool.h>

static bool has_zero(int a[], int n) {
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      return true;
    }
  }

  return false; // Return false at the end after checking all elements.
}

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  int a[5] = {1, 2, 0, 2, 1};
  int b[5] = {1, 2, 3, 4, 5};

  printf("has_zero: %s\n", has_zero(a, ARRAY_COUNT(a)) ? "true" : "false");
  printf("has_zero: %s\n", has_zero(b, ARRAY_COUNT(b)) ? "true" : "false");

  return 0;
}
