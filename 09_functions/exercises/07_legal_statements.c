static int f(int a, int b) {
  return 0;
}

int main(void) {
  int i;
  double x;

  i = f(83, 12);     // a) legal
  x = f(83, 12);     // b) legal, the returned int is promoted to double
  i = f(3.15, 9.28); // c) legal, the double arguments are truncated to int
  x = f(3.15, 9.28); // d) legal, both of the above
  f(83, 12);         // e) legal, the return value is discarded

  return 0;
}
