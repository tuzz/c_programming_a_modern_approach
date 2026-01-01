#define PI 3.14159

int main(void) {
  // a) legal, int is implicitly converted to a char
  char c = 65;

  // b) illegal, variables that have the static storage class have a static
  // storage duration. They must be initialized with a constant value at compile
  // time. Although it is possible to compute i * i at compile time, C takes a
  // simpler approach and does not allow variables to be used for constants.
  // static int i = 5, j = i * i;

  // c) legal, PI is a macro so the constant is evaluated at compile time.
  double d = 2 * PI;

  // d) legal, PI is a macro so the constants are evaluated at compile time.
  double angles[] = {0, PI / 2, PI, 3 * PI / 2};

  return 0;
}
