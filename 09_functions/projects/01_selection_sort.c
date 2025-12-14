#include <stdio.h>
#include <limits.h>

static void selection_sort(int array[], int n) {
  if (n <= 1) { return; }

  int largest = array[0];
  int largest_i = 0;

  for (int i = 1; i < n; i++) {
    if (array[i] > largest) {
      largest = array[i];
      largest_i = i;
    }
  }

  int last = array[n - 1];
  array[n - 1] = largest;
  array[largest_i] = last;

  selection_sort(array, n - 1);
}

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  int a, b, c, d, e;
  printf("Enter five integers: ");
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

  int array[5] = {a, b, c, d, e};
  selection_sort(array, ARRAY_COUNT(array));

  printf("array[0]: %d\n", array[0]);
  printf("array[1]: %d\n", array[1]);
  printf("array[2]: %d\n", array[2]);
  printf("array[3]: %d\n", array[3]);
  printf("array[4]: %d\n", array[4]);

  return 0;
}
