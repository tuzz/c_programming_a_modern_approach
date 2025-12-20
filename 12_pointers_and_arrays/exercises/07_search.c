#include <stdio.h>
#include <stdbool.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

static bool search(const int a[], int n, int key) {
  for (const int *p = a; p < &a[n]; p++) {
    if (*p == key) {
      return true;
    }
  }

  return false;
}

int main(void) {
  int a[5] = {1, 2, 3, 4, 5};

  printf("0: %s\n", search(a, ARRAY_COUNT(a), 0) ? "true" : "false");
  printf("1: %s\n", search(a, ARRAY_COUNT(a), 1) ? "true" : "false");
  printf("2: %s\n", search(a, ARRAY_COUNT(a), 2) ? "true" : "false");
  printf("3: %s\n", search(a, ARRAY_COUNT(a), 3) ? "true" : "false");
  printf("4: %s\n", search(a, ARRAY_COUNT(a), 4) ? "true" : "false");
  printf("5: %s\n", search(a, ARRAY_COUNT(a), 5) ? "true" : "false");
  printf("6: %s\n", search(a, ARRAY_COUNT(a), 6) ? "true" : "false");

  return 0;
}
