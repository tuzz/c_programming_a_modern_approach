#include <stdio.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  float temperature_readings[30][24] = {0};
  float total = 0.0f;

  for (size_t day = 0; day < ARRAY_COUNT(temperature_readings); day++) {
    for (size_t hour = 0; hour < ARRAY_COUNT(temperature_readings[0]); hour++) {
      total += temperature_readings[day][hour];
    }
  }

  float average = total / (ARRAY_COUNT(temperature_readings) * ARRAY_COUNT(temperature_readings[0]));
  printf("The average temperature is: %.1f\n", (double)average);

  return 0;
}
