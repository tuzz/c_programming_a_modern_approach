#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
  int num1, denom1, num2, denom2, result_num, result_denom;

  printf("Enter two fractions separated by a plus, minus, multiply or divide sign: ");
  scanf("%d/%d", &num1, &denom1);
  char operation = (char)getchar();
  scanf("%d/%d", &num2, &denom2);

  switch (operation) {
    case '+':
      result_num = num1 * denom2 + num2 * denom1;
      result_denom = denom1 * denom2;
      break;
    case '-':
      result_num = num1 * denom2 - num2 * denom1;
      result_denom = denom1 * denom2;
      break;
    case '*':
      result_num = num1 * num2;
      result_denom = denom1 * denom2;
      break;
    case '/':
      result_num = num1 * denom2;
      result_denom = num2 * denom1;
      break;
    default:
      printf("Invalid operation: %c\n", operation);
      return 1;
  }

  int m = result_num;
  int n = result_denom;

  while (true) {
    if (n == 0) { break; }

    int remainder = m % n;
    m = n;
    n = remainder;
  }

  printf("The answer is %d/%d\n", result_num / m, result_denom / m);
  return 0;
}
