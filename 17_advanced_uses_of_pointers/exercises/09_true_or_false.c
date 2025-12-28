struct foo { int a; };

int main(void) {
  struct foo x;

  // true, the following expression is equivalent to (*(&s).a) and the dereference
  // operator (*) can be thought of as the inverse of the address operator (&).
  (&s)->a;

  return 0;
}
