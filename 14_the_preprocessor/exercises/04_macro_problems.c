#include <stdio.h>

#define AVG(x,y) (x+y)/2
#define AREA(x,y) (x)*(y)

#define AVG_FIXED(x, y) (((x) + (y)) / 2)
#define AREA_FIXED(x, y) ((x) * (y))

int main(void) {
  // a) Macro expands to 4 / (1 + 1) / 2 so the value is 1.
  printf("%d\n", 4 / AVG(1, 1));

  // Prints "4" as you would expect.
  printf("%d\n", 4 / AVG_FIXED(1, 1));

  // b) Macro expands to 4 / (2) * (2) so the value is 4.
  printf("%d\n", 4 / AREA(2, 2));

  // Prints "1" as you would expect.
  printf("%d\n", 4 / AREA_FIXED(2, 2));

  return 0;
}
