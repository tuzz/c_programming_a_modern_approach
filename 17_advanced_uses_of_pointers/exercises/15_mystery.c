#include <stdio.h>

int f1(int (*f)(int));
int f2(int i);

// This program calls function f2 with incrementing values 0, 1, 2, ... until f2
// returns 0. It then prints the argument that caused f2 to return 0. The
// function f2 computes i^2 + i - 12 as shown below for different values of i.
//
// f2(0) -> -12
// f2(1) -> -10
// f2(2) -> -6
// f2(3) -> 0
//
// Therefore, the program prints "Answer: 3"

int main(void) {
  printf("Answer: %d\n", f1(f2));
  return 0;
}

int f1(int (*f)(int)) {
  int n = 0;
  while ((*f)(n)) n++;
  return n;
}

int f2(int i) {
  return i * i + i - 12;
}
