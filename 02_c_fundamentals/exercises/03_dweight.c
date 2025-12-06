#include <stdio.h>

int main(void) {
  int height = 100;
  int length = 200;
  int width = 300;
  int volume = height * length * width;

  printf("Volume (cubic inches): %d\n", volume);
  printf("Dimensional weight (pounds): %d\n", (volume + 165) / 166);

  return 0;
}
