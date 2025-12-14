#include <stdio.h>
#include <stdbool.h>

static int day_of_year(int month, int day, int year) {
  int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int day_of_year = day;

  for (int i = 0; i < month - 1; i++) {
    day_of_year += month_days[i];
  }

  if (month > 2) {
    bool divisible_by_4 = year % 4 == 0;
    bool divisible_by_100 = year % 100 == 0;
    bool divisible_by_400 = year % 400 == 0;

    if (divisible_by_4 && (!divisible_by_100 || divisible_by_400)) {
      day_of_year += 1;
    }
  }

  return day_of_year;
}

int main(void) {
  printf("day_of_year(1, 1, 2025) returns %d\n", day_of_year(1, 1, 2025));
  printf("day_of_year(3, 1, 2025) returns %d\n", day_of_year(3, 1, 2025));
  printf("day_of_year(3, 1, 2024) returns %d\n", day_of_year(3, 1, 2024));
  printf("day_of_year(3, 1, 2100) returns %d\n", day_of_year(3, 1, 2100));
  printf("day_of_year(3, 1, 2000) returns %d\n", day_of_year(3, 1, 2000));
  printf("day_of_year(12, 31, 2025) returns %d\n", day_of_year(12, 31, 2025));
  printf("day_of_year(12, 31, 2024) returns %d\n", day_of_year(12, 31, 2024));
  return 0;
}
