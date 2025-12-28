#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next;
  int value;
  char _padding[4];
};

static struct node *delete_from_list(struct node *list, int n) {
  struct node *cur, *prev;

  for (cur = list, prev = NULL;
      cur != NULL && cur->value != n;
      prev = cur, cur = cur->next)
    ;

  if (cur == NULL)
    return list;
  if (prev == NULL)
    list = list->next;
  else
    prev->next = cur->next;
  free(cur);
  return list;
}

int main(void) {
  struct node *a = calloc(1, sizeof(*a));
  struct node *b = calloc(1, sizeof(*a));

  a->value = 123;
  b->value = 456;
  a->next = b;

  delete_from_list(a, 999);
  printf("%p\n", (void *)a->next);

  delete_from_list(a, 456);
  printf("%p\n", (void *)a->next);

  return 0;
}
