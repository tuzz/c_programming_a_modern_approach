#include "07_queueADT.h"

#define PUBLIC
#define PRIVATE static

struct node {
  struct node *next;
  Item item;
  char _padding[7];
};

struct queue_type {
  struct node *first_node;
  struct node *last_node;
};

PRIVATE void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

PUBLIC Queue queue_create(void) {
  Queue queue = calloc(1, sizeof(struct queue_type));
  if (!queue) { terminate("Failed to create queue."); }
  return queue;
}

PUBLIC void queue_destroy(Queue q) {
  while (!queue_is_empty(q)) {
    queue_pop_front(q);
  }
  free(q);
}

PUBLIC bool queue_push_back(Queue q, Item item) {
  struct node *node = calloc(1, sizeof(*node));
  if (!node) { terminate("Failed to allocate node."); }
  node->item = item;

  if (q->first_node == NULL) {
    q->first_node = node;
    q->last_node = node;
  } else {
    q->last_node->next = node;
    q->last_node = node;
  }

  return true;
}

PUBLIC Item queue_pop_front(Queue q) {
  if (q->first_node == NULL) {
    return 0;
  } else {
    Item item = q->first_node->item;
    struct node *next = q->first_node->next;

    free(q->first_node);
    q->first_node = next;

    if (q->first_node == NULL) {
      q->last_node = NULL;
    }

    return item;
  }
}

PUBLIC Item queue_first(Queue q) {
  if (q->first_node == NULL) {
    return 0;
  } else {
    return q->first_node->item;
  }
}

PUBLIC Item queue_last(Queue q) {
  if (q->last_node == NULL) {
    return 0;
  } else {
    return q->last_node->item;
  }
}

PUBLIC bool queue_is_empty(Queue q) {
  return q->first_node == NULL;
}
