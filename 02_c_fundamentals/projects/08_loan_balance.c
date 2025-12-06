#include <stdio.h>

int main(void) {
  float amount;
  printf("Enter amount of loan: ");
  scanf("%f", &amount);

  float interest;
  printf("Enter interest rate: ");
  scanf("%f", &interest);

  float payment;
  printf("Enter monthly payment: ");
  scanf("%f", &payment);

  float monthly_interest = (interest / 100.f) / 12.0f;

  // Note: we assume that interest is applied first and then the monthly payment
  // reduces the balance, which is how loans typically work in the real world.

  amount = amount * (1.0f + monthly_interest) - payment;
  printf("Balance remaining after first payment: $%.2f\n", (double)amount);

  amount = amount * (1.0f + monthly_interest) - payment;
  printf("Balance remaining after second payment: $%.2f\n", (double)amount);

  amount = amount * (1.0f + monthly_interest) - payment;
  printf("Balance remaining after third payment: $%.2f\n", (double)amount);

  return 0;
}
