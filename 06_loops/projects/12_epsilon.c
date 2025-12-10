#include <stdio.h>

int main(void) {
  float epsilon;
  printf("Enter epsilon: ");
  scanf("%f", &epsilon);

  float e = 1.0f;
  float added = 1.0f;
  long long int factorial = 1;
  long long int previous = 0;

  for (int term = 1; added >= epsilon; term++) {
    factorial *= term;
    if (factorial < previous) {
      printf("ERROR: factorial overflowed, choose a larger epsilon\n");
      return 1;
    }

    added = 1.0f / (float)factorial;
    e += added;
  }

  printf("e is approximately %.20f\n", (double)e);
  return 0;
}
