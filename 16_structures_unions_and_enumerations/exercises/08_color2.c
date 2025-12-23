#include <stdio.h>
#include <stdbool.h>
#include <math.h>

struct color {
  int red;
  int green;
  int blue;
};

static struct color make_color(int red, int green, int blue) {
  return (struct color){
    .red = red < 0 ? 0 : red > 255 ? 255 : red,
    .green = green < 0 ? 0 : green > 255 ? 255 : green,
    .blue = blue < 0 ? 0 : blue > 255 ? 255 : blue,
  };
}

static int getRed(struct color c) {
  return c.red;
}

static bool equal_color(struct color color1, struct color color2) {
  return color1.red == color2.red && color1.green == color2.green && color1.blue == color2.blue;
}

static struct color brighter(struct color c) {
  if (c.red == 0 && c.green == 0 && c.blue == 0) { return (struct color){3, 3, 3}; }

  if (c.red < 3) { c.red = 3; }
  if (c.green < 3) { c.green = 3; }
  if (c.blue < 3) { c.blue = 3; }

  c.red = (int)lround(c.red / 0.7);
  c.green = (int)lround(c.green / 0.7);
  c.blue = (int)lround(c.blue / 0.7);

  if (c.red > 255) { c.red = 255; }
  if (c.green > 255) { c.green = 255; }
  if (c.blue > 255) { c.blue = 255; }

  return c;
}

static struct color darker(struct color c) {
  c.red = (int)lround(c.red * 0.7);
  c.green = (int)lround(c.green * 0.7);
  c.blue = (int)lround(c.blue * 0.7);

  return c;
}

int main(void) {
  struct color c1 = {0, 0, 0};
  struct color c2 = {1, 2, 10};
  struct color c3 = {240, 255, 150};

  printf("getRed: %d\n", getRed(c3));
  printf("equal_color: %d\n", equal_color(c1, c1));
  printf("equal_color: %d\n", equal_color(c1, c2));

  struct color c4 = brighter(c1);
  struct color c5 = brighter(c2);
  struct color c6 = brighter(c3);
  struct color c7 = darker(c3);

  printf("brighter: %d, %d, %d\n", c4.red, c4.green, c4.blue);
  printf("brighter: %d, %d, %d\n", c5.red, c5.green, c5.blue);
  printf("brighter: %d, %d, %d\n", c6.red, c6.green, c6.blue);
  printf("darker: %d, %d, %d\n", c7.red, c7.green, c7.blue);

  return 0;
}
