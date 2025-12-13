#include <stdio.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  char chess_board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
  };

  for (size_t row = 0; row < ARRAY_COUNT(chess_board); row++) {
    for (size_t column = 0; column < ARRAY_COUNT(chess_board); column++) {
      printf("%c ", chess_board[row][column]);
    }
    putchar('\n');
  }

  return 0;
}
