#include <stdio.h>

static float tax_due(float taxable_income) {
  float tax_due;

  if (taxable_income <= 750.0f) {
    tax_due = 0.01f * taxable_income;
  } else if (taxable_income <= 2250.0f) {
    tax_due = 7.50f + 0.02f * (taxable_income - 750.0f);
  } else if (taxable_income <= 3750.0f) {
    tax_due = 37.50f + 0.03f * (taxable_income - 2250.0f);
  } else if (taxable_income <= 5250.0f) {
    tax_due = 82.50f + 0.04f * (taxable_income - 3750.0f);
  } else if (taxable_income <= 7000.0f) {
    tax_due = 142.50f + 0.05f * (taxable_income - 5250.0f);
  } else {
    tax_due = 230.00f + 0.06f * (taxable_income - 7000.0f);
  }

  return tax_due;
}

int main(void) {
  float taxable_income;
  printf("Enter your taxable income: ");
  scanf("%f", &taxable_income);

  printf("$%.2f tax is due\n", (double)tax_due(taxable_income));
  return 0;
}
