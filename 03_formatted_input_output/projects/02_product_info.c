#include <stdio.h>

int main(void) {
  int item;
  printf("Enter item number: ");
  scanf("%d", &item);

  float price;
  printf("Enter unit price: ");
  scanf("%f", &price);

  int month, day, year;
  printf("Enter purchase date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &day, &year);

  printf("\n");
  printf("Item\t\tUnit\t\tPurchase\n");
  printf("\t\tPrice\t\tDate\n");
  printf("%-d\t\t", item);
  printf("$%7.2f\t", (double)price); // Only one tab is needed because the string is larger than a tab width.
  printf("%-.2d/%-.2d/%-.4d\n", month, day, year);

  return 0;
}
