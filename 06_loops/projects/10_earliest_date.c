#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main(void) {
  int earliest_month = INT_MAX, earliest_day = INT_MAX, earliest_year = INT_MAX;

  while (true) {
    int month, day, year;
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d /%d /%d", &month, &day, &year);
    if (month == 0 && day == 0 && year == 0) { break; }

    if (year < earliest_year) {
      earliest_year = year;
      earliest_month = month;
      earliest_day = day;
    } else if (year > earliest_year) {
      continue;
    }

    if (month < earliest_month) {
      earliest_year = year;
      earliest_month = month;
      earliest_day = day;
    } else if (month > earliest_month) {
      continue;
    }

    if (day < earliest_day) {
      earliest_year = year;
      earliest_month = month;
      earliest_day = day;
    }
  }

  if (earliest_month == INT_MAX) {
    printf("No dates were entered.\n");
  } else {
    printf("%d/%d/%.2d is the earliest date\n", earliest_month, earliest_day, earliest_year);
  }

  return 0;
}
