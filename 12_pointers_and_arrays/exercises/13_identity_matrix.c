#include <stdio.h>

#define N 10

int main(void) {
  double ident[N][N];
  int count = N;

  for (double *p = ident[0]; p < &ident[N][0]; p++) {
    if (count == N) {
      *p = 1.0;
      count = 0;
    } else {
      *p = 0.0;
      count++;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%f ", ident[i][j]);
    }
    printf("\n");
  }

  return 0;
}
