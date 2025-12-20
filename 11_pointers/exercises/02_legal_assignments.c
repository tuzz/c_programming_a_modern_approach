int main(void) {
  int i = 0, *p = &i, *q = &i;

  // a) illegal: cannot assign int * = int
  // p = i;

  // b) illegal: cannot assign int = int *
  // *p = &i;

  // c) illegal: not an lvalue
  // &p = q;

  // d) illegal: cannot assign int * = int
  // p = &q;

  // e) legal
  p = *&q;

  // f) legal
  p = q;

  // g) illegal: cannot assign int * = int
  // p = *q;

  // h) illegal: cannot assign int = int *
  // *p = q;

  // i) legal
  *p = *q;
}
