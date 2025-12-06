#include <stdio.h>

#define PI 3.14159265f

int main(void) {
  float radius = 10.0f;

  float volume1 = 4.0f / 3.0f * PI * radius * radius * radius;
  printf("Volume of sphere using floats: %f\n", (double)volume1);

  float volume2 = 4 / 3 * PI * radius * radius * radius;
  printf("Volume of sphere using integers: %f\n", (double)volume2);

  // You get the wrong answer when using integers because 4 / 3 is truncated to 1.
  // The quotient should be 1.33 so the wrong answer is 75% of the correct answer.

  return 0;
}
