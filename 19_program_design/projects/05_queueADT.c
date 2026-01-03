#include "05_queueADT.h"

#define QUEUE_SIZE 3
#define PUBLIC
#define PRIVATE static

struct queue_type {
  Item *queued_items[QUEUE_SIZE];
  char _padding[4];
  int first_empty_slot;
  int next_to_remove;
  int queue_count;
};

PRIVATE void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

PUBLIC Queue queue_create(void) {
  Queue queue = calloc(1, sizeof(Queue));
  if (!queue) { terminate("Failed to crete queue."); }
  return queue;
}

PUBLIC void queue_destroy(Queue q) {
  free(q);
}

PUBLIC bool queue_push_back(Queue q, Item *item) {
  if (q->queue_count == QUEUE_SIZE) {
    return false;
  } else {
    q->queued_items[q->first_empty_slot++] = item;
    q->first_empty_slot %= QUEUE_SIZE;
    q->queue_count++;
    return true;
  }
}

PUBLIC Item *queue_pop_front(Queue q) {
  if (queue_is_empty(q)) {
    return NULL;
  } else {
    Item *removed = q->queued_items[q->next_to_remove];
    q->queued_items[q->next_to_remove++] = NULL;
    q->next_to_remove %= QUEUE_SIZE;
    q->queue_count--;
    return removed;
  }
}

PUBLIC Item *queue_first(Queue q) {
  if (queue_is_empty(q)) {
    return NULL;
  } else {
    return q->queued_items[q->next_to_remove];
  }
}

PUBLIC Item *queue_last(Queue q) {
  if (queue_is_empty(q)) {
    return NULL;
  } else if (q->first_empty_slot == 0) {
    return q->queued_items[QUEUE_SIZE - 1];
  } else {
    return q->queued_items[q->first_empty_slot - 1];
  }
}

PUBLIC bool queue_is_empty(Queue q) {
  return q->queue_count == 0;
}
