#include "05_token.h"

int evaluate_RPN_expression(const char *expression) {
  int result;

  for (const char *c = expression; *c; c++) {
    switch (*c) {
      case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        push(*c - '0');
        break;
      case '+':
        push(pop() + pop());
        break;
      case '-':
        push(pop() - pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '/':
        push(pop() / pop());
        break;
      case '=':
        result = pop();
        make_empty();
        return result;
      default:
        break;
    }
  }

  return -1;
}
