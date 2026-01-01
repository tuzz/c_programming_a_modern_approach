// a) f is a function that takes:
//  - a pointer to a function that takes a long and returns a float
//  - a pointer to a char
// and returns a pointer to a function that takes a double and returns an int
extern int (*f(float (*)(long), char *))(double);

static float long_to_float(long x) {
  return (float)x;
}

static int double_to_int(double x) {
  return (int)x;
}

int main(void) {
  // b) This style immitates the declration closely:
  int x = (*f(long_to_float, "hello"))(123);

  // Or the following, since calling a function automatically derefs function pointers.
  int y = f(long_to_float, "hello")(123);

  return 0;
}
