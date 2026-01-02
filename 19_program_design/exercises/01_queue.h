#include <stdbool.h>
#include <stdio.h>

// Inserts an item at the end of the queue. Returns false if the queue is full.
bool queue_push_back(Item *item);

// Removes an item from the beginning of the queue. Returns NULL if the queue is empty.
Item *queue_pop_front(void);

// Returns the first item in the queue without changing the queue. Returns NULL if the queue is empty.
Item *queue_first(void);

// Returns the last item in the queue without changing the queue. Returns NULL if the queue is empty.
Item *queue_last(void);

// Tests whether the queue is empty.
bool queue_is_empty(void);
