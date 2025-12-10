#include <stdio.h>

int main(void) {
  int days;
  printf("Enter number of days in month: ");
  scanf("%d", &days);

  int start;
  printf("Enter starting day of the week (1=Sun, 7=Sat): ");
  scanf("%d", &start);

  printf("\nSu Mo Tu We Th Fr Sa\n");
  for (int slot = 1; slot < start; slot++) {
    printf("   ");
  }

  for (int day = 1; day <= days; day++) {
    printf("%3d", day);

    if ((start + day - 1) % 7 == 0) {
      printf("\n");
    }
  }
  printf("\n");

  return 0;
}
