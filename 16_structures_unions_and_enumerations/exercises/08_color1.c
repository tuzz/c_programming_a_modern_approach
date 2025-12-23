struct color {
  int red;
  int green;
  int blue;
};

static const struct color MAGENTA = {255, 0, 255};
static const struct color MAGENTA2 = {.red = 255, .blue = 255};

int main(void) {
  return 0;
}
