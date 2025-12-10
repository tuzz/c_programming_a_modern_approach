#include <stdio.h>

int main(void) {
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  float e = 1.0f;
  long long int factorial = 1;
  long long int previous = 0;

  for (int term = 1; term <= n; term++) {
    factorial *= term;
    if (factorial < previous) {
      printf("ERROR: factorial overflowed at n=%d, choose a smaller n\n", term);
      return 1;
    }

    e += 1.0f / (float)factorial;
  }

  printf("e is approximately %.20f\n", (double)e);
  return 0;
}
