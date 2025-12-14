#include <stdio.h>

static int num_digits(int n) {
  int count = 0;
  do { n /= 10; count++; } while (n != 0);
  return count;
}

int main(void) {
  printf("num_digits(0) returns %d\n", num_digits(0));
  printf("num_digits(1) returns %d\n", num_digits(1));
  printf("num_digits(5) returns %d\n", num_digits(5));
  printf("num_digits(10) returns %d\n", num_digits(10));
  printf("num_digits(55) returns %d\n", num_digits(55));
  printf("num_digits(100) returns %d\n", num_digits(100));
  printf("num_digits(555) returns %d\n", num_digits(555));
  printf("num_digits(1000) returns %d\n", num_digits(1000));
  printf("num_digits(5555) returns %d\n", num_digits(5555));
  return 0;
}
