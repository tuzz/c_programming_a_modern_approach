#include <stdio.h>

static int sum(int (*f)(int), int start, int end) {
  int sum = 0;

  for (int x = start; x <= end; x++) {
    sum += f(x);
  }

  return sum;
}

static int square(int x) {
  return x * x;
}

int main(void) {
  printf("%d\n", sum(square, 3, 5));
  return 0;
}
