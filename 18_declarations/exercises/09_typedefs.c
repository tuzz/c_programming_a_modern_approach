// a) x is an array of 10 pointers to functions that take an int and return a char.
typedef char (*fn_takes_int_returns_char)(int);
static fn_takes_int_returns_char x[10];

// b) x is a function that takes an int and returns a pointer to an array of five ints.
typedef int five_ints[5];
static five_ints *x(int);

// c) x is a function with no parameters the returns a pointer to a function that takes an int and returns a pointer to a float.
typedef float *(*fn_takes_int_returns_ptr_float)(int);
static fn_takes_int_returns_ptr_float x(void);

// d) x is a function that takes an int and a pointer to a function (that takes an int and returns nothing) and returns a pointer to a function that takes an int and returns nothing.
typedef void (*fn_takes_int)(int);
static fn_takes_int x(int, fn_takes_int);

int main(void) {
  return 0;
}
