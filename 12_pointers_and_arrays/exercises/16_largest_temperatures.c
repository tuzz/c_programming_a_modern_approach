#include <stdio.h>
#include <limits.h>

static int *find_largest(int a[], int n) {
  int *largest = a;

  for (int *p = &a[1]; p < &a[n]; p++) {
    if (*p > *largest) {
      largest = p;
    }
  }

  return largest;
}

int main(void) {
  int temperatures[7][24] = {0};

  temperatures[3][14] = 30;
  temperatures[3][15] = 32;
  temperatures[3][16] = 34;

  for (int day = 0; day < 7; day++) {
    int *largest = find_largest(temperatures[day], 24);
    printf("day: %d, largest: %d\n", day, *largest);
  }

  return 0;
}
