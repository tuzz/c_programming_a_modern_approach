int main(void) {
  enum {FALSE, TRUE} b;
  int i;

  // a) legal
  b = FALSE;

  // b) legal
  b = i;

  // c) legal
  b++;

  // d) legal
  i = b;

  // e) legal
  i = 2 * b + 1;
}
