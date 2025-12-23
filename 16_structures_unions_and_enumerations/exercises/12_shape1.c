struct point {
  int x;
  int y;
};

static struct shape {
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
} s;

enum SHAPE_KIND {
  RECTANGLE,
  CIRCLE,
};

int main(void) {
  // a) legal
  s.shape_kind = RECTANGLE;

  // b) legal
  s.center.x = 10;

  // c) illegal, repaired with:
  s.u.rectangle.height = 25;

  // d) illegal, repaired with:
  s.u.circle.radius = 5;

  // e) illegal, repaired with:
  s.u.circle.radius = 5;

  return 0;
}
