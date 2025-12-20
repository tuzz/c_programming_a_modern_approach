#include <stdio.h>
#include <stdbool.h>

static void split_date(int day_of_year, int year, int *month, int *day) {
  int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  bool divisible_by_4 = year % 4 == 0;
  bool divisible_by_100 = year % 100 == 0;
  bool divisible_by_400 = year % 400 == 0;

  if (divisible_by_4 && (!divisible_by_100 || divisible_by_400)) {
    month_days[1] = 29; // It's a leap year.
  }

  int remainder = day_of_year;
  *month = 1;

  for (int i = 0; i < 12; i++) {
    if (remainder > month_days[i]) {
      remainder -= month_days[i];
      *month += 1;
    } else {
      break;
    }
  }

  *day = remainder;
}

int main(void) {
  int day_of_year;
  printf("Enter day of year: ");
  scanf("%d", &day_of_year);

  int year;
  printf("Enter year: ");
  scanf("%d", &year);

  int month = 0;
  int day = 0;
  split_date(day_of_year, year, &month, &day);

  printf("month: %d\n", month);
  printf("day: %d\n", day);
  return 0;
}
