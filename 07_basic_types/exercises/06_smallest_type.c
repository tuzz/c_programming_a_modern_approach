#include <stdio.h>

int main(void) {
  // a) char is sufficient because 31 < (2^7 - 1)
  char days_in_a_month = 31;

  // b) short is sufficient because 366 < (2^15 - 1)
  short days_in_a_year = 366; // leap year

  // c) short is sufficient because 1440 < (2^15 - 1)
  short minutes_in_a_day = 24 * 60;

  // d) long is sufficient because 86400 < (2^31 - 1)
  long seconds_in_a_day = 24 * 60 * 60;

  return 0;
}
