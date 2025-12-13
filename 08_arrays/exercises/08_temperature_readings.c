#include <stdio.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  float temperature_readings[30][24] = {0};

  printf("hours:  ");
  for (size_t hour = 0; hour < ARRAY_COUNT(temperature_readings[0]); hour++) {
    printf("%3zu ", hour);
  }
  putchar('\n');

  for (size_t day = 0; day < ARRAY_COUNT(temperature_readings); day++) {
    printf("day %2zu: ", day);
    for (size_t hour = 0; hour < ARRAY_COUNT(temperature_readings[0]); hour++) {
      printf("%.1f ", (double)temperature_readings[day][hour]);
    }
    putchar('\n');
  }

  return 0;
}
