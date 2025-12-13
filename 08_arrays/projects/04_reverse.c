#include <stdio.h>

#define ARRAY_COUNT(array) ((int)(sizeof(array) / sizeof(array[0])))

int main(void) {
  int a[10], i;

  printf("Enter %d numbers: ", ARRAY_COUNT(a));
  for (i = 0; i < ARRAY_COUNT(a); i++)
    scanf("%d", &a[i]);

  printf("In reverse order:");
  for (i = ARRAY_COUNT(a) - 1; i >= 0; i--)
    printf(" %d", a[i]);
  printf("\n");

  return 0;
}
