#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct stack_type *Stack;

// Creates a new stack on the heap and returns it.
Stack stack_create(void);

// Frees the memory of a stack allocated on the heap.
void stack_destroy(Stack s);

// Empties the stack.
void stack_make_empty(Stack s);

// Checks whether the stack is empty.
bool stack_is_empty(Stack s);

// Checks whether the stack is full.
bool stack_is_full(Stack s);

// Push an item onto the top of the stack. Terminates if the stack is full.
void stack_push(Stack s, Item item);

// Pops an item from the top of the stack. Terminates if the stack is empty.
Item stack_pop(Stack s);

#endif
