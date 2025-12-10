#include <stdio.h>

int main(void) {
  int hours, minutes;
  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hours, &minutes);

  printf("Eqivalent 12-hour time: ");

  if (hours == 0) {
    printf("%d:%.2d AM\n", hours + 12, minutes);
  } else if (hours < 12) {
    printf("%d:%.2d AM\n", hours, minutes);
  } else if (hours == 12) {
    printf("%d:%.2d PM\n", hours, minutes);
  } else {
    printf("%d:%.2d PM\n", hours - 12, minutes);
  }

  return 0;
}
