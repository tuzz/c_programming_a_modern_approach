#include <stdio.h>

struct fraction {
  int numerator;
  int denominator;
};

static struct fraction fraction_reduce(struct fraction f) {
  int m = f.numerator;
  int n = f.denominator;

  while (n != 0) {
    int remainder = m % n;
    m = n;
    n = remainder;
  }

  return (struct fraction){
    .numerator = f.numerator / m,
    .denominator = f.denominator / m,
  };
}

static struct fraction fraction_add(struct fraction f1, struct fraction f2) {
  return fraction_reduce((struct fraction){
    .numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator,
    .denominator = f1.denominator * f2.denominator,
  });
}

static struct fraction fraction_subtract(struct fraction f1, struct fraction f2) {
  return fraction_reduce((struct fraction){
    .numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator,
    .denominator = f1.denominator * f2.denominator,
  });
}

static struct fraction fraction_multiply(struct fraction f1, struct fraction f2) {
  return fraction_reduce((struct fraction){
    .numerator = f1.numerator * f2.numerator,
    .denominator = f1.denominator * f2.denominator,
  });
}

static struct fraction fraction_divide(struct fraction f1, struct fraction f2) {
  return fraction_reduce((struct fraction){
    .numerator = f1.numerator * f2.denominator,
    .denominator = f2.numerator * f1.denominator,
  });
}

int main(void) {
  struct fraction f1 = {.numerator = 2, .denominator = 4};
  struct fraction f2 = {.numerator = 2, .denominator = 3};

  struct fraction reduced = fraction_reduce(f1);
  struct fraction added = fraction_add(f1, f2);
  struct fraction subtracted = fraction_subtract(f1, f2);
  struct fraction multiplied = fraction_multiply(f1, f2);
  struct fraction divided = fraction_divide(f1, f2);

  printf("reduced: numerator=%d, denominator=%d\n", reduced.numerator, reduced.denominator);
  printf("added: numerator=%d, denominator=%d\n", added.numerator, added.denominator);
  printf("subtracted: numerator=%d, denominator=%d\n", subtracted.numerator, subtracted.denominator);
  printf("multiplied: numerator=%d, denominator=%d\n", multiplied.numerator, multiplied.denominator);
  printf("divided: numerator=%d, denominator=%d\n", divided.numerator, divided.denominator);

  return 0;
}
