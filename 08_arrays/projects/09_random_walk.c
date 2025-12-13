#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 10

int main(void) {
  char grid[N][N];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      grid[i][j] = '.';
    }
  }

  // Start in the top-left corner.
  int x = 0;
  int y = 0;
  char letter = 'A';
  grid[0][0] = letter;
  bool can_go_up = false;
  bool can_go_down = true;
  bool can_go_left = false;
  bool can_go_right = true;

  srand((unsigned) time(NULL));

  while (letter < 'Z') {
    int move = rand() % 4;
    bool moved = false;

         if (move == 0 && can_go_up)    { y -= 1; moved = true; }
    else if (move == 1 && can_go_down)  { y += 1; moved = true; }
    else if (move == 2 && can_go_left)  { x -= 1; moved = true; }
    else if (move == 3 && can_go_right) { x += 1; moved = true; }

    if (moved) {
      letter++;
      grid[y][x] = letter;

      can_go_up = y > 0 && grid[y - 1][x] == '.';
      can_go_down = y < N - 1 && grid[y + 1][x] == '.';
      can_go_left = x > 0 && grid[y][x - 1] == '.';
      can_go_right = x < N - 1 && grid[y][x + 1] == '.';

      if (!can_go_up && !can_go_down && !can_go_left && !can_go_right) { break; }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%c ", grid[i][j]);
    }
    printf("\n");
  }

  if (letter != 'Z') {
    printf("I trapped myself!\n");
  }

  return 0;
}
