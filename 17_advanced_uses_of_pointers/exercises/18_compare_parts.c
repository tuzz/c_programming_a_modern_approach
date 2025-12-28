#include <stdio.h>

struct part {
  int number;
};

static int compare_parts(const void *p, const void *q) {
  return ((const struct part *) p)->number - ((const struct part *) q)->number;
}

int main(void) {
  struct part parts[3] = {
    { .number = 2 },
    { .number = 1 },
    { .number = 3 },
  };

  qsort(parts, 3, sizeof(struct part), compare_parts);

  for (int i = 0; i < 3; i++) {
    printf("%d \n", parts[i].number);
  }

  return 0;
}
