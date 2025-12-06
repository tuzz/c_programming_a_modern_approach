#include <stdio.h>

int main(void) {
  int amount;
  printf("Enter a dollar amount: ");
  scanf("%d", &amount);

  int twenties = amount / 20;
  amount -= twenties * 20;

  int tens = amount / 10;
  amount -= tens * 10;

  int fives = amount / 5;
  amount -= fives * 5;

  int ones = amount;

  printf("$20 bills: %d\n", twenties);
  printf("$10 bills: %d\n", tens);
  printf(" $5 bills: %d\n", fives);
  printf(" $1 bills: %d\n", ones);

  return 0;
}
