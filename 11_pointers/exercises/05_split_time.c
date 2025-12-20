#include <stdio.h>

#define SECONDS_PER_MINUTE 60
#define SECONDS_PER_HOUR (60 * SECONDS_PER_MINUTE)

static void split_time(long total_sec, int *hr, int *min, int *sec) {
  *hr = (int)total_sec / SECONDS_PER_HOUR;
  total_sec -= *hr * SECONDS_PER_HOUR;

  *min = (int)total_sec / SECONDS_PER_MINUTE;
  total_sec -= *min * SECONDS_PER_MINUTE;

  *sec = (int)total_sec;
}

int main(void) {
  int hours = 0;
  int minutes = 0;
  int seconds = 0;

  split_time(12345, &hours, &minutes, &seconds);

  printf("hours: %d\n", hours);
  printf("minutes: %d\n", minutes);
  printf("seconds: %d\n", seconds);

  return 0;
}
