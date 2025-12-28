#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next;
  int value;
  char _padding[4];
};

static void delete_from_list(struct node **list, int n) {
  struct node *cur, *prev;

  for (cur = *list, prev = NULL;
      cur != NULL && cur->value != n;
      prev = cur, cur = cur->next)
    ;

  if (cur == NULL)
    return;
  if (prev == NULL)
    *list = (*list)->next;
  else
    prev->next = cur->next;
  free(cur);
}

int main(void) {
  struct node *a = calloc(1, sizeof(*a));
  struct node *b = calloc(1, sizeof(*b));

  a->value = 123;
  b->value = 456;
  a->next = b;

  struct node **list = &a;

  delete_from_list(list, 123);
  printf("%d\n", (*list)->value);

  return 0;
}
