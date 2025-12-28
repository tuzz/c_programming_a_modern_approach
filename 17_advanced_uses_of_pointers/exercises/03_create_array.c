#include <stdio.h>
#include <stdlib.h>

static int *create_array(int n, int intial_value) {
  int *array = malloc((unsigned long)n * sizeof(*array));
  if (!array) { return NULL; }

  for (int i = 0; i < n; i++) {
    array[i] = intial_value;
  }

  return array;
}

int main(void) {
  int *array = create_array(5, 3);

  for (int i = 0; i < 5; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}
