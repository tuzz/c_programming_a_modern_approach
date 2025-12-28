#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next;
  int value;
  char _padding[4];
};

int main(void) {
  struct node *a = calloc(1, sizeof(*a));
  struct node *b = calloc(1, sizeof(*b));

  a->value = 123;
  b->value = 456;
  a->next = b;

  // The problem with this approach is that we try to read p->next after p was freed.
  // for (struct node *p = a; p != NULL; p = p->next)
  //   free(p);

  // To fix it, we can keep store p->next before p is freed, then advance to it.
  for (struct node *p = a, *next; p != NULL; p = next) {
    next = p->next;
    free(p);
  }

  return 0;
}
