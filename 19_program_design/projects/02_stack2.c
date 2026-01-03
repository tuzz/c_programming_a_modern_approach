typedef char Item;
#include "../exercises/04_stack_linked_list.c"

int main(void) {
  Stack stack = stack_create();
  bool running = true;

  while (running) {
    printf("Enter an RPN expression: ");

    char c;
    bool reading = true;
    while (reading) {
      scanf(" %c", &c);

      switch (c) {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
          stack_push(stack, c - '0');
          break;
        case '+':
          stack_push(stack, stack_pop(stack) + stack_pop(stack));
          break;
        case '-':
          stack_push(stack, stack_pop(stack) - stack_pop(stack));
          break;
        case '*':
          stack_push(stack, stack_pop(stack) * stack_pop(stack));
          break;
        case '/':
          stack_push(stack, stack_pop(stack) / stack_pop(stack));
          break;
        case '=':
          printf("Value of expression: %d\n", stack_pop(stack));
          stack_make_empty(stack);
          reading = false;
          break;
        case 'q':
          reading = false;
          running = false;
          break;
        default:
          break;
      }
    }
  }

  if (!stack_is_empty(stack)) {
    printf("Not enough operands in expression\n");
  }

  return 0;
}
