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

  int num_payments;
  printf("Enter number of payments: ");
  scanf("%d", &num_payments);

  float monthly_interest = (interest / 100.f) / 12.0f;

  for (int i = 0; i < num_payments; i++) {
    amount = amount * (1.0f + monthly_interest) - payment;
    printf("Balance remaining after first payment: $%.2f\n", (double)amount);
  }

  return 0;
}
