static struct {
  union {
    char a, b;
    int c;
  } d;
  int e[5];
} f, *p = &f;

int main(void) {
  // a) illegal
  // p->b = ' ';

  // b) legal
  p->e[3] = 10;

  // c) legal
  (*p).d.a = '*';

  // d) illegal
  // p->d->c = 20;

  return 0;
}
