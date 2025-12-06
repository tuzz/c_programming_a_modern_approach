#include <stdio.h>

int main(void) {
  float x;
  printf("Enter x: ");
  scanf("%f", &x);

  float answer = ((((3.0f * x + 2.0f) * x - 5.0f) * x - 1.0f) * x + 7.0f) * x - 6.0f;
  printf("The answer is %f\n", (double)answer);

  return 0;
}
