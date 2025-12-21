#include <stdio.h>
#include <string.h>

static char *duplicate(const char *p) {
  char *q;

  // This function is incorrect because q is uninitialized so could point anywhere
  // in memory. When we try to copy the string pointed to by p into q, it would
  // write to some arbitrary location and the program would most likely segfault.
  strcpy(q, p);
  return q;
}

int main(void) {
  return 0;
}
