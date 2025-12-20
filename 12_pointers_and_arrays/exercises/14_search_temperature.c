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
  int temperatures[7][24] = {0};

  temperatures[3][14] = 30;
  temperatures[3][15] = 32;
  temperatures[3][16] = 34;

  bool found = search(temperatures[0], 7 * 24, 32);
  printf("%s\n", found ? "true" : "false");

  return 0;
}
