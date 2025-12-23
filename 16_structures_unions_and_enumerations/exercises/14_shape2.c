#include <stdio.h>
#include <math.h>
#define PI 3.14159265

struct point {
  int x;
  int y;
};

struct shape {
  int shape_kind;
  struct point center;
  union {
    struct {
      int height, width;
    } rectangle;
    struct {
      int radius;
    } circle;
  } u;
};

enum SHAPE_KIND {
  RECTANGLE,
  CIRCLE,
};

static double area(struct shape s) {
  if (s.shape_kind == RECTANGLE) {
    return (double)(s.u.rectangle.height * s.u.rectangle.width);
  } else {
    return PI * s.u.circle.radius * s.u.circle.radius;
  }
}

static struct shape move(struct shape s, int x, int y) {
  s.center.x += x;
  s.center.y += y;
  return s;
}

static struct shape scale(struct shape s, double c) {
  if (s.shape_kind == RECTANGLE) {
    s.u.rectangle.width = (int)lround(c * s.u.rectangle.width);
    s.u.rectangle.height = (int)lround(c * s.u.rectangle.height);
  } else {
    s.u.circle.radius = (int)lround(c * s.u.circle.radius);
  }

  return s;
}

int main(void) {
  struct shape r = {
    .shape_kind = RECTANGLE,
    .center.x = 50,
    .center.y = 100,
    .u.rectangle.height = 10,
    .u.rectangle.width = 20,
  };

  struct shape c = {
    .shape_kind = CIRCLE,
    .center.x = 70,
    .center.y = 80,
    .u.circle.radius = 10,
  };

  struct shape moved = move(r, 3, 5);
  struct shape rs = scale(r, 1.6);
  struct shape cs = scale(c, 1.6);

  printf("rectangle area: %f\n", area(r));
  printf("circle area: %f\n", area(c));
  printf("rectangle moved: %d, %d\n", moved.center.x, moved.center.y);
  printf("rectangle scaled: %d, %d\n", rs.u.rectangle.height, rs.u.rectangle.width);
  printf("circle scaled: %d\n", cs.u.circle.radius);

  return 0;
}
