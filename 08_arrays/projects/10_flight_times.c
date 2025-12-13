#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  int hours, minutes;
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hours, &minutes);

  int minutes_since_midnight = hours * 60 + minutes;

  int departure_times[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};
  int arrival_times[8] = {616, 712, 811, 900, 968, 1075, 1280, 1438};
  int closest = INT_MAX;
  size_t closest_i = SIZE_MAX;

  for (size_t i = 0; i < ARRAY_COUNT(departure_times); i++) {
    int delta = abs(departure_times[i] - minutes_since_midnight);
    if (delta < closest) { closest = delta; closest_i = i; }
  }

  int departure_hour = departure_times[closest_i] / 60;
  int departure_minute = departure_times[closest_i] % 60;
  char* departure_suffix = departure_hour < 12 ? "a.m." : "p.m.";
  if (departure_hour > 12) { departure_hour -= 12; }

  int arrival_hour = arrival_times[closest_i] / 60;
  int arrival_minute = arrival_times[closest_i] % 60;
  char* arrival_suffix = arrival_hour < 12 ? "a.m." : "p.m.";
  if (arrival_hour > 12) { arrival_hour -= 12; }

  printf("Closest departure time is %d:%.2d %s, arriving at %d:%.2d %s\n",
    departure_hour, departure_minute, departure_suffix, arrival_hour, arrival_minute, arrival_suffix);

  return 0;
}
