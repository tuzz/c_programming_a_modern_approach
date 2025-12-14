#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 10

static void generate_random_walk(char walk[N][N]) {
  // Start in the top-left corner.
  int x = 0;
  int y = 0;
  char letter = 'A';
  walk[0][0] = letter;
  bool can_go_up = false;
  bool can_go_down = true;
  bool can_go_left = false;
  bool can_go_right = true;

  while (letter < 'Z') {
    int move = rand() % 4;
    bool moved = false;

         if (move == 0 && can_go_up)    { y -= 1; moved = true; }
    else if (move == 1 && can_go_down)  { y += 1; moved = true; }
    else if (move == 2 && can_go_left)  { x -= 1; moved = true; }
    else if (move == 3 && can_go_right) { x += 1; moved = true; }

    if (moved) {
      letter++;
      walk[y][x] = letter;

      can_go_up = y > 0 && walk[y - 1][x] == '.';
      can_go_down = y < N - 1 && walk[y + 1][x] == '.';
      can_go_left = x > 0 && walk[y][x - 1] == '.';
      can_go_right = x < N - 1 && walk[y][x + 1] == '.';

      if (!can_go_up && !can_go_down && !can_go_left && !can_go_right) { break; }
    }
  }
}

static void print_array(char walk[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%c ", walk[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  char walk[N][N];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      walk[i][j] = '.';
    }
  }

  srand((unsigned) time(NULL));
  generate_random_walk(walk);
  print_array(walk);

  return 0;
}
