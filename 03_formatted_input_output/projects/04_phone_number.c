#include <stdio.h>

int main(void) {
  printf("Enter phone number [(xxx) xxx-xxxx]: ");
  int a, b, c;
  scanf("(%d) %d-%d", &a, &b, &c);
  printf("You entered %d.%d.%d\n", a, b, c);
  return 0;
}
