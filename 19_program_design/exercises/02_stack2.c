#include <stdio.h>
#include <stdlib.h>
#include "02_stack2.h"


struct node {
  struct node *next;
  int data;
  char _padding[4];
};

static struct node *top = NULL;

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

void make_empty(void) {
  while (!is_empty())
    pop();
}

bool is_empty(void) {
  return top == NULL;
}

bool is_full(void) {
  return false;
}

void push(int i) {
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL)
    terminate("Error in push: stack is full.");

  new_node->data = i;
  new_node->next = top;
  top = new_node;
}

int pop(void) {
  struct node *old_top;
  int i;

  if (is_empty())
    terminate("Error in pop: stack is empty.");

  old_top = top;
  i = top->data;
  top = top->next;
  free(old_top);
  return i;
}
