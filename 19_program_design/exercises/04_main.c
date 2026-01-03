typedef char Item;
//#include "04_stack_array.c";
#include "04_stack_linked_list.c"

int main(void) {
  Stack stack = stack_create();

  stack_push(stack, 'a');
  stack_push(stack, 'b');
  stack_push(stack, 'c');

  printf("%s\n", stack_is_full(stack) ? "full" : "not full");
  printf("%s\n", stack_is_empty(stack) ? "empty" : "not empty");
  printf("popped: %c\n", stack_pop(stack));

  printf("%s\n", stack_is_full(stack) ? "full" : "not full");
  printf("%s\n", stack_is_empty(stack) ? "empty" : "not empty");
  printf("popped: %c\n", stack_pop(stack));

  printf("%s\n", stack_is_full(stack) ? "full" : "not full");
  printf("%s\n", stack_is_empty(stack) ? "empty" : "not empty");
  printf("popped: %c\n", stack_pop(stack));

  printf("%s\n", stack_is_full(stack) ? "full" : "not full");
  printf("%s\n", stack_is_empty(stack) ? "empty" : "not empty");

  return 0;
}
