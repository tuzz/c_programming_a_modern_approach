#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct queue_type *Queue;

// Creates a new queue and returns it. Returns NULL if fails to allocate memory.
Queue queue_create(void);

// Destroys a queue, freeing its memory.
void queue_destroy(Queue q);

// Inserts an item at the end of the queue. Returns false if the queue is full.
bool queue_push_back(Queue q, Item *item);

// Removes an item from the beginning of the queue. Returns NULL if the queue is empty.
Item *queue_pop_front(Queue q);

// Returns the first item in the queue without changing the queue. Returns NULL if the queue is empty.
Item *queue_first(Queue q);

// Returns the last item in the queue without changing the queue. Returns NULL if the queue is empty.
Item *queue_last(Queue q);

// Tests whether the queue is empty.
bool queue_is_empty(Queue q);
