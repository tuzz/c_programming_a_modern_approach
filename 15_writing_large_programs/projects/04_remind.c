#include <stdio.h>
#include <string.h>
#include "04_readline.h"

#define MAX_REMIND 50
#define MSG_LEN 60
#define DATE_LEN 11

int main(void) {
  char reminders[MAX_REMIND][MSG_LEN + 3];
  char date_str[DATE_LEN + 1], msg_str[MSG_LEN + 1];
  int month, day, hours, minutes, i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter month, day, 24-hour time and reminder: ");
    scanf("%2d/%2d", &month, &day);
    if (month == 0 || day == 0) {
      break;
    } else if (month < 0 || month > 12 || day < 0 || day > 31) {
      printf("Error: date is invalid, skipping\n");
      continue;
    }
    scanf("%2d:%2d", &hours, &minutes);
    sprintf(date_str, "%d/%d %.2d:%.2d", month, day, hours, minutes);
    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++)
      if (strcmp(date_str, reminders[i]) < 0) // Will secondary sort by 24-hour time.
        break;
    for(j = num_remind; j > i; j--)
      strcpy(reminders[j], reminders[j-1]);

    strcpy(reminders[i], date_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nDate Time  Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);

  return 0;
}
