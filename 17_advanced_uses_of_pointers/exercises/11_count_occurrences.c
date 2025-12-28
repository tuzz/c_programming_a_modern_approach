#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next;
  int value;
  char _padding[4];
};

static int count_occurrences(struct node *list, int n) {
  int count = 0;

  for (struct node *p = list; p; p = p->next) {
    if (p->value == n) { count++; }
  }

  return count;
}

int main(void) {
  struct node *a = calloc(1, sizeof(*a));
  struct node *b = calloc(1, sizeof(*b));
  struct node *c = calloc(1, sizeof(*c));

  a->value = 123;
  b->value = 456;
  c->value = 456;
  a->next = b;
  b->next = c;

  printf("%d\n", count_occurrences(a, 123));
  printf("%d\n", count_occurrences(a, 456));
  printf("%d\n", count_occurrences(a, 789));

  return 0;
}
