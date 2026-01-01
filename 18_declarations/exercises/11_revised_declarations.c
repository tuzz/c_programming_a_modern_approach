// f is a function that takes an int and returns a pointer to an array of ints.
static int (*f(int))[];

// g is a function that takes an int and returns a pointer to a function that takes an int and returns an int.
static int (*g(int))(int);

// a is an array of 10 pointers to functions that take an int and return an int.
static int (*a[10])(int);

int main(void) {
  return 0;
}
