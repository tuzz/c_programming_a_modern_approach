#include <stdio.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  int array[5][5];

  for (size_t row = 0; row < ARRAY_COUNT(array); row++) {
    printf("Enter row %zu: ", row + 1);

    for (size_t column = 0; column < ARRAY_COUNT(array[0]); column++) {
      scanf("%d", &array[row][column]);
    }
  }

  printf("\nRow totals: ");
  for (size_t row = 0; row < ARRAY_COUNT(array); row++) {
    int row_total = 0;
    for (size_t column = 0; column < ARRAY_COUNT(array[0]); column++) {
      row_total += array[row][column];
    }
    printf("%d ", row_total);
  }

  printf("\nColumn totals: ");
  for (size_t column = 0; column < ARRAY_COUNT(array[0]); column++) {
    int column_total = 0;
    for (size_t row = 0; row < ARRAY_COUNT(array); row++) {
      column_total += array[row][column];
    }
    printf("%d ", column_total);
  }
  printf("\n");
}
