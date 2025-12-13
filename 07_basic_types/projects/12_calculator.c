#include <stdio.h>

int main(void) {
  float result;
  printf("Enter an expression: ");
  scanf("%f", &result);

  char operation;
  float number;

  while ((operation = (char)getchar()) != '\n') {
    scanf("%f", &number);

    switch (operation) {
      case '+': result += number; break;
      case '-': result -= number; break;
      case '*': result *= number; break;
      case '/': result /= number; break;
      default:
        printf("Invalid operation: %c\n", operation);
        return 1;
    }
  }

  printf("Value of expression: %f\n", (double)result);
  return 0;
}
