#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

int main(void) {
  bool running = true;
  while (running) {
    printf("Enter an RPN expression: ");

    char c;
    bool reading = true;
    while (reading) {
      scanf(" %c", &c);

      switch (c) {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
          push(c - '0');
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
          printf("Value of expression: %d\n", pop());
          make_empty();
          reading = false;
          break;
        case 'q':
          reading = false;
          running = false;
          break;
        default:
          break;
      }
    }
  }

  if (!is_empty()) {
    printf("Not enough operands in expression\n");
  }

  return 0;
}
