#include <stdio.h>

typedef struct { int month; int day; int year; } Date;

static int compare_dates(Date d1, Date d2) {
  if (d1.year < d2.year) { return -1; } else if (d1.year > d2.year) { return 1; }
  if (d1.month < d2.month) { return -1; } else if (d1.month > d2.month) { return 1; }
  if (d1.day < d2.day) { return -1; } else if (d1.day > d2.day) { return 1; }
  return 0;
}

int main(void) {
  int month1, day1, year1;
  printf("Enter first date (mm/dd/yy): ");
  scanf("%d /%d /%d", &month1, &day1, &year1);
  Date date1 = {month1, day1, year1};

  int month2, day2, year2;
  printf("Enter second date (mm/dd/yy): ");
  scanf("%d /%d /%d", &month2, &day2, &year2);
  Date date2 = {month2, day2, year2};

  switch (compare_dates(date1, date2)) {
    case -1:
      printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", month1, day1, year1, month2, day2, year2);
      break;
    case 0:
      printf("The dates are the same.\n");
      break;
    case 1:
      printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", month2, day2, year2, month1, day1, year1);
      break;
    default:
      break;
  }

  return 0;
}
