#include "04_stack.h"

#define PUBLIC
#define PRIVATE static

struct stack_type {
  struct node *top;
};

struct node {
  struct node *next;
  Item item;
  char _padding[7];
};

PRIVATE void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

PUBLIC Stack stack_create(void) {
  Stack stack = calloc(1, sizeof(*stack));
  if (!stack) { terminate("Failed to allocate memory for a Stack"); }
  return stack;
}

PUBLIC void stack_destroy(Stack s) {
  stack_make_empty(s);
  free(s);
}

void stack_make_empty(Stack s) {
  for (struct node *p = s->top, *next; p; p = next) {
    next = p->next;
    free(p);
  }
  s->top = NULL;
}

bool stack_is_empty(Stack s) {
  return !s->top;
}

bool stack_is_full(Stack s) {
  return false;
}

void stack_push(Stack s, Item item) {
  struct node *node = calloc(1, sizeof(*node));
  if (!node) { terminate("Failed to allocate memory for a Stack node"); }
  node->item = item;
  node->next = s->top;
  s->top = node;
}

Item stack_pop(Stack s) {
  if (stack_is_empty(s)) { terminate("Stack underflow"); }
  Item item = s->top->item;
  struct node *next = s->top->next;
  free(s->top);
  s->top = next;
  return item;
}
