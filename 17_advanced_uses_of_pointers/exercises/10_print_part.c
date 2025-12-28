#include <stdio.h>

#define NAME_LEN 100

struct part {
  int number;
  int on_hand;
  char name[NAME_LEN+1];
  char _padding[3];
};

static void print_part(struct part *p) {
  printf("Part number: %d\n", p->number);
  printf("Part name: %s\n", p->name);
  printf("Quantity on hand: %d\n", p->on_hand);
}

int main(void) {
  struct part p = { .number = 123, .name = "something", .on_hand = 5 };
  print_part(&p);
  return 0;
}
