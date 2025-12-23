#include <stdio.h>

#define SECONDS_PER_MINUTE 60
#define SECONDS_PER_HOUR (60 * SECONDS_PER_MINUTE)

struct time {
  int hours;
  int minutes;
  int seconds;
};

static struct time split_time(long total_seconds) {
  struct time time;

  time.hours = (int)total_seconds / SECONDS_PER_HOUR;
  total_seconds -= time.hours * SECONDS_PER_HOUR;

  time.minutes = (int)total_seconds / SECONDS_PER_MINUTE;
  total_seconds -= time.minutes * SECONDS_PER_MINUTE;

  time.seconds = (int)total_seconds;
  return time;
}

int main(void) {
  struct time time = split_time(12345);

  printf("hours: %d\n", time.hours);
  printf("minutes: %d\n", time.minutes);
  printf("seconds: %d\n", time.seconds);

  return 0;
}
