#include "06_queueADT.h"

#define PUBLIC
#define PRIVATE static

struct queue_type {
  Item *queued_items;
  int first_empty_slot;
  int next_to_remove;
  int queue_count;
  int size;
};

PRIVATE void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

PUBLIC Queue queue_create(int size) {
  Queue queue = calloc(1, sizeof(struct queue_type));
  if (!queue) { terminate("Failed to create queue."); }

  queue->queued_items = calloc((unsigned long)size, sizeof(Item));
  if (!queue->queued_items) { terminate("Failed to create queued_items."); }

  queue->size = size;
  return queue;
}

PUBLIC void queue_destroy(Queue q) {
  free(q->queued_items);
  free(q);
}

PUBLIC bool queue_push_back(Queue q, Item item) {
  if (q->queue_count == q->size) {
    return false;
  } else {
    q->queued_items[q->first_empty_slot++] = item;
    q->first_empty_slot %= q->size;
    q->queue_count++;
    return true;
  }
}

PUBLIC Item queue_pop_front(Queue q) {
  if (queue_is_empty(q)) {
    terminate("Cannot pop from an empty queue.");
    return 0;
  } else {
    Item removed = q->queued_items[q->next_to_remove];
    q->queued_items[q->next_to_remove++] = 0;
    q->next_to_remove %= q->size;
    q->queue_count--;
    return removed;
  }
}

PUBLIC Item queue_first(Queue q) {
  if (queue_is_empty(q)) {
    return 0;
  } else {
    return q->queued_items[q->next_to_remove];
  }
}

PUBLIC Item queue_last(Queue q) {
  if (queue_is_empty(q)) {
    return 0;
  } else if (q->first_empty_slot == 0) {
    return q->queued_items[q->size - 1];
  } else {
    return q->queued_items[q->first_empty_slot - 1];
  }
}

PUBLIC bool queue_is_empty(Queue q) {
  return q->queue_count == 0;
}
