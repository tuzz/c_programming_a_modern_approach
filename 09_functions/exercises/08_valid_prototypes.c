void f(double x); // a) valid
void f(double);   // b) valid, unnamed parameter
void f(x);        // c) invalid, types must be provided
f(double x);      // d) invalid, f implicitly returns int, rather than void (illegal in C99)

int main(void) {
  return 0;
}
