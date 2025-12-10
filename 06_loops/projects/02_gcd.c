#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int a, b;
  printf("Enter two integers: ");
  scanf("%d%d", &a, &b);

  int m = a;
  int n = b;

  while (true) {
    if (n == 0) { break; }

    int remainder = m % n;
    m = n;
    n = remainder;
  }
  printf("Greatest common divisor: %d\n", m);

  return 0;
}
