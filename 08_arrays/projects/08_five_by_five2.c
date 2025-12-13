#include <stdio.h>
#include <limits.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  int array[5][5];

  for (size_t row = 0; row < ARRAY_COUNT(array); row++) {
    printf("Enter student %zu quiz grades: ", row + 1);

    for (size_t column = 0; column < ARRAY_COUNT(array[0]); column++) {
      scanf("%d", &array[row][column]);
    }
  }

  printf("\n");
  for (size_t row = 0; row < ARRAY_COUNT(array); row++) {
    int total = 0;
    for (size_t column = 0; column < ARRAY_COUNT(array[0]); column++) {
      total += array[row][column];
    }
    float average = (float)total / ARRAY_COUNT(array[0]);
    printf("Student %zu scored a total of %d with average %.1f\n", row + 1, total, (double)average);
  }

  printf("\n");
  for (size_t column = 0; column < ARRAY_COUNT(array[0]); column++) {
    int total = 0;
    int high = INT_MIN;
    int low = INT_MAX;

    for (size_t row = 0; row < ARRAY_COUNT(array); row++) {
      int score = array[row][column];
      total += score;

      if (score > high) {
        high = score;
      } else if (score < low) {
        low = score;
      }
    }

    float average = (float)total / ARRAY_COUNT(array);
    printf("Quiz %zu had an average score of %.1f with a high of %d and low of %d\n", column + 1, (double)average, high, low);
  }
  printf("\n");

  return 0;
}
