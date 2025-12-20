#include <stdio.h>

int main(void) {
  int temperatures[7][24] = {0};

  temperatures[3][14] = 30;
  temperatures[3][15] = 32;
  temperatures[3][16] = 34;

  int i = 3;
  for (int *p = temperatures[i]; p < &temperatures[i][24]; p++) {
    printf("%d ", *p);
  }
  printf("\n");

  return 0;
}
