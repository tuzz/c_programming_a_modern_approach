#include "01_queue.h"

#define PUBLIC
#define PRIVATE static
#define QUEUE_SIZE 3

PRIVATE Item *queued_items[QUEUE_SIZE];
PRIVATE int first_empty_slot = 0;
PRIVATE int next_to_remove = 0;
PRIVATE int queue_count = 0;

PUBLIC bool queue_push_back(Item *item) {
  if (queue_count == QUEUE_SIZE) {
    return false;
  } else {
    queued_items[first_empty_slot++] = item;
    first_empty_slot %= QUEUE_SIZE;
    queue_count++;
    return true;
  }
}

PUBLIC Item *queue_pop_front(void) {
  if (queue_is_empty()) {
    return NULL;
  } else {
    Item *removed = queued_items[next_to_remove];
    queued_items[next_to_remove++] = NULL;
    next_to_remove %= QUEUE_SIZE;
    queue_count--;
    return removed;
  }
}

PUBLIC Item *queue_first(void) {
  if (queue_is_empty()) {
    return NULL;
  } else {
    return queued_items[next_to_remove];
  }
}

PUBLIC Item *queue_last(void) {
  if (queue_is_empty()) {
    return NULL;
  } else if (first_empty_slot == 0) {
    return queued_items[QUEUE_SIZE - 1];
  } else {
    return queued_items[first_empty_slot - 1];
  }
}

PUBLIC bool queue_is_empty(void) {
  return queue_count == 0;
}

// Note: this assumes Item is a char.
PUBLIC void print_queue(void) {
  for (int i = 0; i < QUEUE_SIZE; i++) {
    Item *m = queued_items[i];
    printf("%c", m ? *m : ' ');
  }
  printf("\n");
}
