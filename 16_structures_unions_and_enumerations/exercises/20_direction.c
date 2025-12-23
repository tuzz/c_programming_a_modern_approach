#include <stdio.h>

int main(void) {
  enum {NORTH, SOUTH, EAST, WEST} direction = EAST;

  int x = 0;
  int y = 0;

  switch (direction) {
    case EAST: x++;  break;
    case WEST: x--;  break;
    case SOUTH: y++; break;
    case NORTH: y--; break;
    default:         break;
  }

  printf("%d, %d\n", x, y);

  return 0;
}
