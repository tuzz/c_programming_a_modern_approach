static int a;

static void f(int b) {
  int c;
  // a) Visible in this scope: a, b, c
}

static void g(void) {
  int d;
  {
    int e;
    // c) Visible in this scope: a, d, e
  }
  // b) Visible in this scope: a, d
}

int main(void) {
  int f;
  // d) Visible in this scope: a, f
  return 0;
}
