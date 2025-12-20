#include <stdio.h>

static void avg_sum(double a[], int n, double *avg, double *sum) {
  *sum = 0.0;

  for (int i = 0; i < n; i++) {
    *sum += a[i];
  }

  *avg = *sum / n;
}

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  double a[5] = {1.0, 2.0, 3.0, 4.0, 5.0};

  double avg = 0;
  double sum = 0;
  avg_sum(a, ARRAY_COUNT(a), &avg, &sum);

  printf("avg: %f\n", avg);
  printf("sum: %f\n", sum);

  return 0;
}
