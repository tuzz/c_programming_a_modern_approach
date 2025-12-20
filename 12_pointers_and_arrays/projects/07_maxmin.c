#include <stdio.h>

static void max_min(int a[], int n, int *max, int *min) {
  *max = *min = a[0];

  for (int *p = a; p < &a[n]; p++) {
    if (*p > *max)
      *max = *p;
    else if (*p < *min)
      *min = *p;
  }
}

int main(void) {
  int a[5] = {2, 5, 3, 1, 4};

  int max = 0;
  int min = 0;
  max_min(a, 5, &max, &min);

  printf("max: %d\n", max);
  printf("min: %d\n", min);

  return 0;
}
