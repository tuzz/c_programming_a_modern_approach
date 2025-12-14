#include <stdio.h>

static void create_magic_square(int n, char magic_square[n][n]) {
  // Clear the variable-length array to zero.
  for (int row = 0; row < n; row++) {
    for (int column = 0; column < n; column++) {
      magic_square[row][column] = 0;
    }
  }

  // Start by placing the number 1 in the middle of row 0.
  int y = 0;
  int x = n / 2;
  magic_square[y][x] = 1;

  for (int i = 2; i <= n * n; i++) {
    // Move up one row, wrapping around to the last row.
    int diagonal_y = (y > 0) ? y - 1 : n - 1;

    // Move right one column, wrapping around to the first column.
    int diagonal_x = (x < n - 1) ? x + 1 : 0;

    if (magic_square[diagonal_y][diagonal_x] == 0) {
      // If the square is not occupied, place the number diagonally.
      y = diagonal_y;
      x = diagonal_x;
    } else {
      // Otherwise, place the number below the previous number.
      y = (y < n - 1) ? y + 1 : 0;
    }

    magic_square[y][x] = i;
  }
}

static void print_magic_square(int n, char magic_square[n][n]) {
  for (int row = 0; row < n; row++) {
    for (int column = 0; column < n; column++) {
      printf("%2d ", magic_square[row][column]);
    }
    printf("\n");
  }
}

int main(void) {
  printf("This program creates a magic square of specified size.\n");
  printf("The size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic square: ");
  int n;
  scanf("%d", &n);

  if (n < 1 || n > 99 || n % 2 == 0) {
    printf("n is invalid\n");
    return 1;
  }

  char magic_square[n][n];
  create_magic_square(n, magic_square);
  print_magic_square(n, magic_square);

  return 0;
}
