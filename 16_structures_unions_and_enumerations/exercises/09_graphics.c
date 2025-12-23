#include <stdio.h>
#include <stdbool.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };

static int area(struct rectangle r) {
  int width = r.lower_right.x - r.upper_left.x;
  int height = r.lower_right.y - r.upper_left.y;

  return width * height;
}

static struct point center(struct rectangle r) {
  int width = r.lower_right.x - r.upper_left.x;
  int height = r.lower_right.y - r.upper_left.y;

  return (struct point){
    .x = r.upper_left.x + width / 2,
    .y = r.upper_left.y + height / 2,
  };
}

static struct rectangle move(struct rectangle r, int x, int y) {
  return (struct rectangle) {
    .upper_left.x = r.upper_left.x + x,
    .upper_left.y = r.upper_left.y + y,

    .lower_right.x = r.lower_right.x + x,
    .lower_right.y = r.lower_right.y + y,
  };
}

static bool contains(struct rectangle r, struct point p) {
  return r.upper_left.x <= p.x && p.x <= r.lower_right.x && r.upper_left.y <= p.y && p.y <= r.lower_right.y;
}

int main(void) {
  struct rectangle r1 = {
    .upper_left.x = 10,
    .upper_left.y = 20,
    .lower_right.x = 100,
    .lower_right.y = 200,
  };

  struct point c = center(r1);
  struct rectangle m = move(r1, 3, 5);
  bool contained1 = contains(r1, (struct point){50, 50});
  bool contained2 = contains(r1, (struct point){50, 999});
  bool contained3 = contains(r1, (struct point){0, 999});

  printf("area: %d\n", area(r1));
  printf("center: %d, %d\n", c.x, c.y);
  printf("moved: (%d, %d), (%d, %d)\n", m.upper_left.x, m.upper_left.y, m.lower_right.x, m.lower_right.y);
  printf("contains: %d, %d, %d\n", contained1, contained2, contained3);

  return 0;
}
