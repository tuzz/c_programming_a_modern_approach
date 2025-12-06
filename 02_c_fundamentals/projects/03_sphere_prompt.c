#include <stdio.h>

#define PI 3.14159265f

int main(void) {
  float radius;
  printf("Enter sphere radius: ");
  scanf("%f", &radius);

  float volume = 4.0f / 3.0f * PI * radius * radius * radius;
  printf("Volume of sphere: %f\n", (double)volume);

  return 0;
}
