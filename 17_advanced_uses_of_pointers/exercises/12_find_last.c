#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next;
  int value;
  char _padding[4];
};

static struct node *find_last(struct node *list, int n) {
  struct node *last = NULL;

  for (struct node *p = list; p; p = p->next) {
    if (p->value == n) { last = p; }
  }

  return last;
}

int main(void) {
  struct node *a = calloc(1, sizeof(*a));
  struct node *b = calloc(1, sizeof(*b));
  struct node *c = calloc(1, sizeof(*c));

  a->value = 123;
  b->value = 123;
  c->value = 456;
  a->next = b;
  b->next = c;

  struct node *last_123 = find_last(a, 123);

  if (last_123 == a) {
    printf("last 123 is node a\n");
  }

  if (last_123 == b) {
    printf("last 123 is node b\n");
  }

  if (last_123 == c) {
    printf("last 123 is node c\n");
  }

  return 0;
}
