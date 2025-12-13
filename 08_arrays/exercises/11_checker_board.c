#include <stdio.h>
#include <stdbool.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  char checker_board[8][8];
  bool parity = false;

  // Initialize the checker board.
  for (size_t row = 0; row < ARRAY_COUNT(checker_board); row++) {
    for (size_t column = 0; column < ARRAY_COUNT(checker_board[0]); column++) {
      checker_board[row][column] = parity ? 'R' : 'B';
      parity = !parity;
    }
    parity = !parity;
  }

  // Print out the checker board.
  for (size_t row = 0; row < ARRAY_COUNT(checker_board); row++) {
    for (size_t column = 0; column < ARRAY_COUNT(checker_board[0]); column++) {
      printf("%c ", checker_board[row][column]);
    }
    putchar('\n');
  }

  return 0;
}
