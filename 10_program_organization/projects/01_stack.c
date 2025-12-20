#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

static void stack_overflow(void) {
  printf("Stack overflow\n");
  exit(1);
}

static void stack_underflow(void) {}

static char contents[STACK_SIZE];
static int top = 0;

static void make_entry(void) {
  top = 0;
}

static bool is_empty(void) {
  return top == 0;
}

static bool is_full(void) {
  return top == STACK_SIZE;
}

static void push(char c) {
  if (is_full()) {
    stack_overflow();
  } else {
    contents[top++] = c;
  }
}

static char pop(void) {
  if (is_empty()) {
    stack_underflow();
    return '\0';
  } else {
    return contents[--top];
  }
}

int main(void) {
  printf("Enter parentheses and/or braces: ");

  char c, d;
  while ((c = (char)getchar()) != '\n') {
    if (c == '(' || c == '{') {
      push(c);
    } else if (c == ')') {
      d = pop();
      if (d != '(') { push(d); break; }
    } else if (c == '}') {
      d = pop();
      if (d != '{') { push(d); break; }
    }
  }

  if (is_empty()) {
    printf("Parentheses/braces are nested properly\n");
  } else {
    printf("Parentheses/braces are NOT nested properly\n");
  }

  return 0;
}
