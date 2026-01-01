#include <stdio.h>

static void print_error(const char *message) {
  static int n = 1; // <-- Fix: add the "static" storage class
  printf("Error %d: %s\n", n++, message);
}

int main(void) {
  print_error("first");
  print_error("second");
  return 0;
}
