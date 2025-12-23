#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
  int departure_time;
  int arrival_time;
} FlightTime;

static const FlightTime FLIGHT_TIMES[8] = {
  { .departure_time = 480, .arrival_time = 616 },
  { .departure_time = 583, .arrival_time = 712 },
  { .departure_time = 679, .arrival_time = 811 },
  { .departure_time = 767, .arrival_time = 900 },
  { .departure_time = 840, .arrival_time = 968 },
  { .departure_time = 945, .arrival_time = 1075 },
  { .departure_time = 1140, .arrival_time = 1280 },
  { .departure_time = 1305, .arrival_time = 1438 },
};

int main(void) {
  int hours, minutes;
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hours, &minutes);
  int minutes_since_midnight = hours * 60 + minutes;

  int closest = INT_MAX;
  size_t closest_i = SIZE_MAX;

  for (size_t i = 0; i < sizeof(FLIGHT_TIMES) / sizeof(FLIGHT_TIMES[0]); i++) {
    int delta = abs(FLIGHT_TIMES[i].departure_time - minutes_since_midnight);
    if (delta < closest) { closest = delta; closest_i = i; }
  }

  printf("Closest departure time is FLIGHT_TIMES[%zu].\n", closest_i);
  return 0;
}
