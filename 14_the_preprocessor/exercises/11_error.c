#include <stdio.h>

#define ERROR(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)

int main(void) {
  ERROR("hello %d\n", 123);
  return 0;
}
