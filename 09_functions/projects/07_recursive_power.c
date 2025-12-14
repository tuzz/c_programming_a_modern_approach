#include <stdio.h>

static int power(int x, int n) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    int root = power(x, n / 2);
    return root * root;
  } else {
    return x * power(x, n - 1);
  }
}

int main(void) {
  int x;
  printf("Enter x: ");
  scanf("%d", &x);

  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  printf("%d^%d = %d\n", x, n, power(x, n));
  return 0;
}
