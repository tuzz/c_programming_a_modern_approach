#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next;
  int value;
  char _padding[4];
};

static struct node *delete_from_list(struct node *list, int n) {
  // Check if the list is empty.
  if (!list) { return list; }

  struct node *p = list;

  // Check if n is at the start of the list.
  if (list->value == n) {
    list = list->next;
    free(p);
    return list;
  }

  // Find the node immediately before n.
  while (p->next && p->next->value != n) {
    p = p->next;
  }

  // Shift the value of node i+2 into i+1.
  while (p->next && p->next->next) {
    p->next->value = p->next->next->value;
    p = p->next;
  }

  // Discard the surplus node at the end.
  free(p->next);
  p->next = NULL;

  // Is this really what the exercise wants? If so, it's asking us to implement
  // a less efficient algorithm O(N) to save one variable and requires us to
  // come up with a novel ideal to treat the linked list like a normal array.

  return list;
}

int main(void) {
  struct node *a = calloc(1, sizeof(*a));
  struct node *b = calloc(1, sizeof(*b));

  a->value = 123;
  b->value = 456;
  a->next = b;

  delete_from_list(a, 999);
  printf("%p\n", (void *)a->next);

  delete_from_list(a, 456);
  printf("%p\n", (void *)a->next);

  return 0;
}
