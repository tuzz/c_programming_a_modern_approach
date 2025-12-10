#include <stdio.h>

int main(void) {
  int a, b, c, d;
  printf("Enter four integers: ");
  scanf("%d%d%d%d", &a, &b, &c, &d);

  int min_ab, max_ab;

  if (a < b) {
    min_ab = a;
    max_ab = b;
  } else {
    min_ab = b;
    max_ab = a;
  }

  int min_cd, max_cd;;

  if (c < d) {
    min_cd = c;
    max_cd = d;
  } else {
    min_cd = d;
    max_cd = c;
  }

  int min_abcd;

  if (min_ab < min_cd) {
    min_abcd = min_ab;
  } else {
    min_abcd = min_cd;
  }

  int max_abcd;

  if (max_ab > max_cd) {
    max_abcd = max_ab;
  } else {
    max_abcd = max_cd;
  }

  printf("Largest: %d\n", max_abcd);
  printf("Smallest: %d\n", min_abcd);

  return 0;
}
