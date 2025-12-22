#include <stdio.h>
#include <stdbool.h>

int main(void) {
  char *month_names[] = {"", "January", "February", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};

  int month, day, year;
  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%d /%d /%d", &month, &day, &year);

  bool valid = month >= 1 && month <= 12 && day >= 1 && day <= 31 && year >= 1;
  if (!valid) { printf("Date is invalid\n"); return 1; }

  printf("You entered the date %s %d, %d\n", month_names[month], day, year);
  return 0;
}
