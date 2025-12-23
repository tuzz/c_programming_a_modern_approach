int main(void) {
  struct { int x, y; } x;
  struct { int x, y; } y;

  x.x = 1;
  x.y = 2;

  y.x = 3;
  y.y = 4;

  // Yes, these declarations are legal on an individual basis because the name
  // of the variable is in a different namespace to the struct's members.
  //
  // Both declarations may appear in the same program. Each will be an anonymous
  // struct but they won't be compatible with each other, so this won't work:
  // x = y;

  return 0;
}
