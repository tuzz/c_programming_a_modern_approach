typedef char Item;
//#include "03_queue_array.c"     // Part a)
#include "03_queue_linked_list.c" // Part b)

int main(void) {
  Item a = 'a';
  Item b = 'b';
  Item c = 'c';
  Item d = 'd';
  Item e = 'e';
  bool pushed;

  pushed = queue_push_back(&a);
  printf("%s: %c\n", pushed ? "pushed" : "failed to push", a);
  print_queue();

  pushed = queue_push_back(&b);
  printf("%s: %c\n", pushed ? "pushed" : "failed to push", b);
  print_queue();

  pushed = queue_push_back(&c);
  printf("%s: %c\n", pushed ? "pushed" : "failed to push", c);
  print_queue();

  pushed = queue_push_back(&c);
  printf("%s: %c\n", pushed ? "pushed" : "failed to push", c);
  print_queue();

  Item *x = queue_pop_front();
  printf("popped: %c\n", *x);
  print_queue();

  Item *first = queue_first();
  printf("first: %c\n", *first);
  print_queue();

  Item *last = queue_last();
  printf("last: %c\n", *last);
  print_queue();

  Item *y = queue_pop_front();
  printf("popped: %c\n", *y);
  print_queue();

  pushed = queue_push_back(&d);
  printf("%s: %c\n", pushed ? "pushed" : "failed to push", d);
  print_queue();

  pushed = queue_push_back(&e);
  printf("%s: %c\n", pushed ? "pushed" : "failed to push", e);
  print_queue();

  Item *z = queue_pop_front();
  printf("popped: %c\n", *z);
  print_queue();

  Item *w = queue_pop_front();
  printf("popped: %c\n", *w);
  print_queue();

  bool empty1 = queue_is_empty();
  printf("%s\n", empty1 ? "queue is empty" : "queue is not empty");

  Item *q = queue_pop_front();
  printf("popped: %c\n", *q);
  print_queue();

  bool empty2 = queue_is_empty();
  printf("%s\n", empty2 ? "queue is empty" : "queue is not empty");

  if (!empty2) {
    Item *r = queue_pop_front();
    printf("popped: %c\n", *r);
    print_queue();

    bool empty3 = queue_is_empty();
    printf("%s\n", empty3 ? "queue is empty" : "queue is not empty");
  }

  return 0;
}
