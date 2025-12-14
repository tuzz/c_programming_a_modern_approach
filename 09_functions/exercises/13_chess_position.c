#include <stdio.h>

#define N 8

static int evaluate_position(char board[N][N]) {
  int difference = 0;

  for (int row = 0; row < N; row++) {
    for (int column = 0; column < N; column++) {
      switch (board[row][column]) {
        case 'Q': difference += 9; break;
        case 'R': difference += 5; break;
        case 'B': difference += 3; break;
        case 'N': difference += 3; break;
        case 'P': difference += 1; break;

        case 'q': difference -= 9; break;
        case 'r': difference -= 5; break;
        case 'b': difference -= 3; break;
        case 'n': difference -= 3; break;
        case 'p': difference -= 1; break;
        default:                   break;
      }
    }
  }

  return difference;
}

int main(void) {
  char board[N][N] = {
    { ' ', 'K', 'R', ' ', 'Q', 'B', ' ', 'R' },
    { ' ', 'P', 'P', ' ', ' ', ' ', 'P', 'P' },
    { 'P', ' ', ' ', ' ', ' ', 'P', 'N', ' ' },
    { ' ', 'N', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', 'q', ' ' },
    { ' ', 'p', ' ', ' ', 'p', ' ', ' ', ' ' },
    { 'p', 'b', 'p', ' ', ' ', 'p', 'p', 'p' },
    { ' ', 'k', 'r', ' ', ' ', 'b', ' ', 'r' },
  };

  printf("difference: %d\n", evaluate_position(board));

  return 0;
}
