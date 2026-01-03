typedef char Item;
#include "../exercises/04_stack_linked_list.c"

int main(void) {
  printf("Enter parentheses and/or braces: ");
  Stack stack = stack_create();

  char c, d;
  while ((c = (char)getchar()) != '\n') {
    if (c == '(' || c == '{') {
      stack_push(stack, c);
    } else if (c == ')') {
      d = stack_pop(stack);
      if (d != '(') { stack_push(stack, d); break; }
    } else if (c == '}') {
      d = stack_pop(stack);
      if (d != '{') { stack_push(stack, d); break; }
    }
  }

  if (stack_is_empty(stack)) {
    printf("Parentheses/braces are nested properly\n");
  } else {
    printf("Parentheses/braces are NOT nested properly\n");
  }

  return 0;
}
