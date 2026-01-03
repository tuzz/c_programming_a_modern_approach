#include "04_stack.h"

#define MAX_STACK_SIZE 3
#define PUBLIC
#define PRIVATE static

struct stack_type {
  int top;
  int size;
  Item contents[MAX_STACK_SIZE];
  char _padding[1];
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
  free(s);
}

void stack_make_empty(Stack s) {
  s->top = 0;
}

bool stack_is_empty(Stack s) {
  return s->size == 0;
}

bool stack_is_full(Stack s) {
  return s->size == MAX_STACK_SIZE;
}

void stack_push(Stack s, Item item) {
  if (stack_is_full(s)) { terminate("Stack overflow"); }
  s->contents[s->top++] = item;
  s->size++;
}

Item stack_pop(Stack s) {
  if (stack_is_empty(s)) { terminate("Stack underflow"); }
  Item item = s->contents[--s->top];
  s->size--;
  return item;
}
