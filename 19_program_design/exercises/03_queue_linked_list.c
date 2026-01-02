#include "01_queue.h"
#include <stdlib.h>

#define PUBLIC
#define PRIVATE static

struct node {
  Item *item;
  struct node *next;
};

PRIVATE struct node *first_node;
PRIVATE struct node *last_node;

PRIVATE void terminate(void) {
  printf("Failed to allocate memory.\n");
  exit(EXIT_FAILURE);
}

PUBLIC bool queue_push_back(Item *item) {
  struct node *node = calloc(1, sizeof(*node));
  if (!node) { terminate(); }
  node->item = item;

  if (first_node == NULL) {
    first_node = node;
    last_node = node;
  } else {
    last_node->next = node;
    last_node = node;
  }

  return true;
}

PUBLIC Item *queue_pop_front(void) {
  if (first_node == NULL) {
    return NULL;
  } else {
    Item *item = first_node->item;
    struct node *next = first_node->next;

    free(first_node);
    first_node = next;

    if (first_node == NULL) {
      last_node = NULL;
    }

    return item;
  }
}

PUBLIC Item *queue_first(void) {
  if (first_node == NULL) {
    return NULL;
  } else {
    return first_node->item;
  }
}

PUBLIC Item *queue_last(void) {
  if (last_node == NULL) {
    return NULL;
  } else {
    return last_node->item;
  }
}

PUBLIC bool queue_is_empty(void) {
  return first_node == NULL;
}

// Note: this assumes Item is a char.
PUBLIC void print_queue(void) {
  for (struct node *p = first_node; p; p = p->next) {
    printf("%c", *p->item);
  }
  printf("\n");
}
