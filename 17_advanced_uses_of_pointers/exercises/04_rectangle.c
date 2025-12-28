#include <stdlib.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };
static struct rectangle *p;

int main(void) {
  p = calloc(1, sizeof(*p));

  p->upper_left.x = 10;
  p->upper_left.y = 5;
  p->lower_right.x = 20;
  p->lower_right.y = 15;

  return 0;
}
