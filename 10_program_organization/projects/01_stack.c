#include <stdbool.h>

#define STACK_SIZE 100

static void stack_overflow(void) {}
static void stack_underflow(void) {}

static int contents[STACK_SIZE];
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

static void push(int i) {
  if (is_full()) {
    stack_overflow();
  } else {
    contents[top++] = i;
  }
}

static int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return 0;
  } else {
    return contents[--top];
  }
}

int main(void) {
  return 0;
}
