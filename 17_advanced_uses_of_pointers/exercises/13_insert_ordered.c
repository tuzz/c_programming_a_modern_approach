#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next;
  int value;
  char _padding[4];
};

// The problem with this approach is that it assumes the element to insert is
// somewhere in the middle of the list. If it is at the beginning the prev is
// NULL and setting prev->next would dereference a NULL pointer and crash. If it
// is at the end then cur->value would dereference a NULL pointer and crash.
static struct node *insert_into_ordered_list(struct node *list, struct node *new_node) {
  struct node *cur = list, *prev = NULL;
  // We can fix it by adding cur != NULL to the loop condition.
  while (cur && cur->value <= new_node->value) {
    prev = cur;
    cur = cur->next;
  }
  // And by handling the start-of-list case explicitly.
  if (!prev) {
    new_node->next = list;
    return new_node;
  }
  prev->next = new_node;
  new_node->next = cur;
  return list;
}

int main(void) {
  struct node *a = calloc(1, sizeof(*a));
  struct node *b = calloc(1, sizeof(*b));
  struct node *c = calloc(1, sizeof(*c));
  struct node *d = calloc(1, sizeof(*d));
  struct node *e = calloc(1, sizeof(*e));

  a->value = 2;
  b->value = 1;
  c->value = 3;
  d->value = 5;
  e->value = 4;

  struct node *list = a;
  list = insert_into_ordered_list(list, b);
  list = insert_into_ordered_list(list, c);
  list = insert_into_ordered_list(list, d);
  list = insert_into_ordered_list(list, e);

  for (struct node *p = list; p; p = p->next) {
    printf("%d\n", p->value);
  }

  return 0;
}
