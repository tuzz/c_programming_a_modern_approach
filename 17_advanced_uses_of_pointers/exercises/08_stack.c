#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct node {
  struct node *next;
  int value;
  char _padding[4];
};

static struct node *top = NULL;

static void stack_underflow(void) {}

static void make_empty(void) {
  for (struct node *p = top, *next; p != NULL; p = next) {
    next = p->next;
    free(p);
  }

  top = NULL;
}

static bool is_empty(void) {
  return !top;
}

static bool push(int value) {
  struct node *new_top = calloc(1, sizeof(*new_top));
  if (!new_top) { return false; }

  new_top->next = top;
  new_top->value = value;

  top = new_top;
  return true;
}

static int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return 0;
  }

  struct node *previous_top = top;
  int previous_value = top->value;

  top = top->next;
  free(previous_top);

  return previous_value;
}

int main(void) {
  push(123);
  push(456);
  push(789);

  printf("popped %d\n", pop());
  printf("%s\n", is_empty() ? "empty" : "not empty");

  printf("popped %d\n", pop());
  printf("%s\n", is_empty() ? "empty" : "not empty");

  printf("popped %d\n", pop());
  printf("%s\n", is_empty() ? "empty" : "not empty");

  printf("popped %d\n", pop()); // Stack underflow.
  printf("%p\n", (void *)top);

  return 0;
}
