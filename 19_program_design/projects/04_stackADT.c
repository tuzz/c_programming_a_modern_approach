#include <stdio.h>
#include <stdlib.h>
#include "04_stackADT.h"

#define STACK_SIZE 100

struct stack_type {
  void *contents[STACK_SIZE];
  char _padding[4];
  int top;
};

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create(void) {
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL)
    terminate("Error in create: stack could not be created.");
  s->top = 0;
  return s;
}

void destroy(Stack s) {
  free(s);
}

void make_empty(Stack s) {
  s->top = 0;
}

bool is_empty(Stack s) {
  return s->top == 0;
}

bool is_full(Stack s) {
  return s->top == STACK_SIZE;
}

void push(Stack s, void *item) {
  if (is_full(s))
    terminate("Error in push: stack is full.");
  s->contents[s->top++] = item;
}

void *pop(Stack s) {
  if (is_empty(s))
    terminate("Error in pop: stack is empty.");
  return s->contents[--s->top];
}

void *peek(Stack s) {
  if (is_empty(s))
    terminate("Error in peek: stack is empty.");
  return s->contents[s->top - 1];
}

int main(void) {
  Stack stack = create();
  char *string = "hello";

  push(stack, string);
  printf("peeked: %s\n", (char *)peek(stack));
  printf("peeked: %s\n", (char *)peek(stack));
  printf("%s\n", (char *)pop(stack));
  printf("%s\n", (char *)pop(stack));

  return 0;
}
