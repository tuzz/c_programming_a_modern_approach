#include <stdio.h>

int main(void) {
  int hours, minutes;
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hours, &minutes);

  int minutes_since_midnight = hours * 60 + minutes;

  int departure1 = 8 * 60;
  int departure2 = 9 * 60 + 43;
  int departure3 = 11 * 60 + 19;
  int departure4 = 12 * 60 + 47;
  int departure5 = 14 * 60;
  int departure6 = 15 * 60 + 45;
  int departure7 = 19 * 60;
  int departure8 = 21 * 60 + 45;

  if (minutes_since_midnight <= (departure1 + departure2) / 2) {
    printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
  } else if (minutes_since_midnight <= (departure2 + departure3) / 2) {
    printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
  } else if (minutes_since_midnight <= (departure3 + departure4) / 2) {
    printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
  } else if (minutes_since_midnight <= (departure4 + departure5) / 2) {
    printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
  } else if (minutes_since_midnight <= (departure5 + departure6) / 2) {
    printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
  } else if (minutes_since_midnight <= (departure6 + departure7) / 2) {
    printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
  } else if (minutes_since_midnight <= (departure7 + departure8) / 2) {
    printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
  } else {
    printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
  }

  return 0;
}
