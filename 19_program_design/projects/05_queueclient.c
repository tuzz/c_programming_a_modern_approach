typedef char Item;
#include "05_queueADT.c"

int main(void) {
  Queue q1 = queue_create();
  Queue q2 = queue_create();
  Item a = 'a';
  Item b = 'b';
  bool pushed;

  pushed = queue_push_back(q1, &a);
  printf("q1 %s: %c\n", pushed ? "pushed" : "failed to push", a);

  pushed = queue_push_back(q1, &b);
  printf("q1 %s: %c\n", pushed ? "pushed" : "failed to push", b);

  printf("\n");

  pushed = queue_push_back(q2, &b);
  printf("q2 %s: %c\n", pushed ? "pushed" : "failed to push", b);

  pushed = queue_push_back(q2, &a);
  printf("q2 %s: %c\n", pushed ? "pushed" : "failed to push", a);

  printf("\n");

  while (!queue_is_empty(q1)) {
    Item *item = queue_pop_front(q1);
    printf("q1 popped: %c\n", *item);
  }

  printf("\n");

  while (!queue_is_empty(q2)) {
    Item *item = queue_pop_front(q2);
    printf("q2 popped: %c\n", *item);
  }

  queue_destroy(q1);
  queue_destroy(q2);

  return 0;
}
