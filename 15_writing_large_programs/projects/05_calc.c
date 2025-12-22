#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "05_token.h"

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  char expression[100] = "";

  while (true) {
    printf("Enter an RPN expression: ");

    fgets(expression, ARRAY_COUNT(expression), stdin);
    if (expression[0] == 'q') { break; }

    int result = evaluate_RPN_expression(expression);
    if (result == -1) { printf("Missing = at the end of the expresson\n"); continue; }

    printf("Value of expression: %d\n", result);
  }

  return 0;
}
