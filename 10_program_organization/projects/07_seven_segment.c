#include <stdio.h>
#include <stdbool.h>

#define MAX_DIGITS 10

static const int segments[MAX_DIGITS][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, // 9
};
static char digits[4][MAX_DIGITS * 4];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void) {
  clear_digits_array();
  printf("Enter a number: ");

  char c;
  int num_digits = 0;
  while ((c = (char)getchar()) != '\n' && num_digits < 10) {
    if (c >= '0' && c <= '9') {
      process_digit(c - '0', num_digits);
      num_digits++;
    }
  }

  print_digits_array();
}

void clear_digits_array(void) {
  for (int row = 0; row < 4; row++) {
    for (int column = 0; column < MAX_DIGITS * 4; column++) {
      digits[row][column] = ' ';
    }
  }
}

// Seven segment layout:
//
//   _0_
// 5|   |1
//  |_6_|
//  |   |2
// 4|___|
//    3
//
// Character digit layout:
//
//    012
// 0:  _
// 1: |_|
// 2: |_|

void process_digit(int digit, int position) {
  for (int i = 0; i < 7; i++) {
    int offset = position * 4;

    if (segments[digit][i]) {
      switch (i) {
        case 0: digits[0][offset + 1] = '_'; break;
        case 1: digits[1][offset + 2] = '|'; break;
        case 2: digits[2][offset + 2] = '|'; break;
        case 3: digits[2][offset + 1] = '_'; break;
        case 4: digits[2][offset + 0] = '|'; break;
        case 5: digits[1][offset + 0] = '|'; break;
        case 6: digits[1][offset + 1] = '_'; break;
        default: break;
      }
    }
  }
}

void print_digits_array(void) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < MAX_DIGITS * 4; column++) {
      putchar(digits[row][column]);
    }
    putchar('\n');
  }
}
