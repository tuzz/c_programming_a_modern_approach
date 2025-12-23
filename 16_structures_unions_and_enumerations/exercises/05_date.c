#include <stdio.h>
#include <stdbool.h>

struct date {
  int month;
  int day;
  int year;
};

static int day_of_year(struct date d) {
  int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int day_of_year = d.day;

  for (int i = 0; i < d.month - 1; i++) {
    day_of_year += month_days[i];
  }

  if (d.month > 2) {
    bool divisible_by_4 = d.year % 4 == 0;
    bool divisible_by_100 = d.year % 100 == 0;
    bool divisible_by_400 = d.year % 400 == 0;

    if (divisible_by_4 && (!divisible_by_100 || divisible_by_400)) {
      day_of_year += 1;
    }
  }

  return day_of_year;
}

static int compare_dates(struct date d1, struct date d2) {
  if (d1.year < d2.year) {
    return -1;
  } else if (d1.year > d2.year) {
    return 1;
  }

  if (d1.month < d2.month) {
    return -1;
  } else if (d1.month > d2.month) {
    return 1;
  }

  if (d1.day < d2.day) {
    return -1;
  } else if (d1.day > d2.day) {
    return 1;
  }

  return 0;
}

int main(void) {
  printf("day_of_year((struct date){1, 1, 2025}) returns %d\n", day_of_year((struct date){1, 1, 2025}));
  printf("day_of_year((struct date){3, 1, 2025}) returns %d\n", day_of_year((struct date){3, 1, 2025}));
  printf("day_of_year((struct date){3, 1, 2024}) returns %d\n", day_of_year((struct date){3, 1, 2024}));
  printf("day_of_year((struct date){3, 1, 2100}) returns %d\n", day_of_year((struct date){3, 1, 2100}));
  printf("day_of_year((struct date){3, 1, 2000}) returns %d\n", day_of_year((struct date){3, 1, 2000}));
  printf("day_of_year((struct date){12, 31, 2025}) returns %d\n", day_of_year((struct date){12, 31, 2025}));
  printf("day_of_year((struct date){12, 31, 2024}) returns %d\n", day_of_year((struct date){12, 31, 2024}));
  return 0;
}
