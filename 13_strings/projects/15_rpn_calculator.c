#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))
#define STACK_SIZE 100

static void stack_overflow(void) {
  printf("Expression is too complex\n");
  exit(1);
}

static void stack_underflow(void) {}

static int contents[STACK_SIZE];
static int top = 0;

static void make_empty(void) {
  top = 0;
}

static bool is_empty(void) {
  return top == 0;
}

static bool is_full(void) {
  return top == STACK_SIZE;
}

static void push(int c) {
  if (is_full()) {
    stack_overflow();
  } else {
    contents[top++] = c;
  }
}

static int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return '\0';
  } else {
    return contents[--top];
  }
}

static int evaluate_RPN_expression(const char *expression) {
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
