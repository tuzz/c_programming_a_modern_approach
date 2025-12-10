#include <stdio.h>

int main(void) {
  printf("This program prints a table of squares.\n");

  int n;
  printf("Enter number of entries in table: ");
  scanf("%d", &n);

  int square = 1;
  int odd = 3;
  for (int i = 1; i <= n; i++) {
    printf("%10d%10d\n", i, square);
    square += odd;
    odd += 2;
  }

  return 0;
}
