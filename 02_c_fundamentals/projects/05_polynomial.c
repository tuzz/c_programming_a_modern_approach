#include <stdio.h>

int main(void) {
  float x;
  printf("Enter x: ");
  scanf("%f", &x);

  float square = x * x;
  float cube = x * square;
  float fourth = x * cube;
  float fifth = x * fourth;

  float answer = (3.0f * fifth) + (2.0f * fourth) - (5.0f * cube) - (square) + (7.0f * x) - 6.0f;
  printf("The answer is %f\n", (double)answer);

  return 0;
}
