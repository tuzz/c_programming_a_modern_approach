#include <stdio.h>

// a)
struct complex {
  double real;
  double imaginary;
};

// c)
static struct complex make_complex(double real, double imaginary) {
  return (struct complex){.real = real, .imaginary = imaginary};
}

// d)
static struct complex add_complex(struct complex c1, struct complex c2) {
  return (struct complex){
    .real = c1.real + c2.real,
    .imaginary = c1.imaginary + c2.imaginary,
  };
}

int main(void) {
  // b)
  struct complex c1, c2, c3;

  c1.real = 1.0;
  c1.imaginary = 2.0;

  c2.real = 3.0;
  c2.imaginary = 4.0;

  c3.real = 5.0;
  c3.imaginary = 6.0;

  struct complex c4 = add_complex(c1, add_complex(c2, c3));
  printf("c4: real=%f, imaginary=%f\n", c4.real, c4.imaginary);

  return 0;
}
