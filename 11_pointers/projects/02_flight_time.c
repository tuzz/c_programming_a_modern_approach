#include <stdio.h>

static void find_closest_flight(int desired_time, int *departure_time, int *arrival_time) {
  int departure1 = 8 * 60;
  int departure2 = 9 * 60 + 43;
  int departure3 = 11 * 60 + 19;
  int departure4 = 12 * 60 + 47;
  int departure5 = 14 * 60;
  int departure6 = 15 * 60 + 45;
  int departure7 = 19 * 60;
  int departure8 = 21 * 60 + 45;

  int arrival1 = 10 * 60 + 16;
  int arrival2 = 11 * 60 + 52;
  int arrival3 = 13 * 60 + 31;
  int arrival4 = 15 * 60;
  int arrival5 = 16 * 60 + 8;
  int arrival6 = 17 * 60 + 55;
  int arrival7 = 21 * 60 + 20;
  int arrival8 = 23 * 60 + 58;

  if (desired_time <= (departure1 + departure2) / 2) {
    *departure_time = departure1;
    *arrival_time = arrival1;
  } else if (desired_time <= (departure2 + departure3) / 2) {
    *departure_time = departure2;
    *arrival_time = arrival2;
  } else if (desired_time <= (departure3 + departure4) / 2) {
    *departure_time = departure3;
    *arrival_time = arrival3;
  } else if (desired_time <= (departure4 + departure5) / 2) {
    *departure_time = departure4;
    *arrival_time = arrival4;
  } else if (desired_time <= (departure5 + departure6) / 2) {
    *departure_time = departure5;
    *arrival_time = arrival5;
  } else if (desired_time <= (departure6 + departure7) / 2) {
    *departure_time = departure6;
    *arrival_time = arrival6;
  } else if (desired_time <= (departure7 + departure8) / 2) {
    *departure_time = departure7;
    *arrival_time = arrival7;
  } else {
    *departure_time = departure8;
    *arrival_time = arrival8;
  }
}

int main(void) {
  int hours, minutes;
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hours, &minutes);

  int minutes_since_midnight = hours * 60 + minutes;
  int departure_time = 0;
  int arrival_time = 0;
  find_closest_flight(minutes_since_midnight, &departure_time, &arrival_time);

  printf("departure_time: %d\n", departure_time);
  printf("arrival_time: %d\n", arrival_time);

  return 0;
}
