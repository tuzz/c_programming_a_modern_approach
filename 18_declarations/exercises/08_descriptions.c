// a) x is an array of 10 pointers to functions that take an int and return a char.
char (*x[10])(int);

// b) x is a function that takes an int and returns a pointer to an array of five ints.
int (*x(int))[5];

// c) x is a function with no parameters the returns a pointer to a function that takes an int and returns a pointer to a float.
float *(*x(void))(int);

// d) x is a function that takes an int and a pointer to a function (that takes an int and returns nothing) and returns a pointer to a function that takes an int and returns nothing.
void (*x(int, void (*y)(int)))(int);

int main(void) {
  return 0;
}
