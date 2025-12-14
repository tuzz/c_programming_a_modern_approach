#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

static int roll_dice(void) {
  int first_roll = rand() % 6;
  int second_roll = rand() % 6;

  return first_roll + second_roll;
}

static bool play_game(void) {
  int rolled = roll_dice();
  printf("You rolled: %d\n", rolled);

  switch (rolled) {
    case 7: case 11:
      return true; // The player wins if the sum of the dice is 7 or 11.
    case 2: case 3: case 12:
      return false; // The player loses if the sum of the dice is 2, 3 or 12.
    default:
      break;
  }

  // Any other roll is called the "point".
  int point = rolled;
  printf("Your point is: %d\n", point);

  while (true) {
    rolled = roll_dice();
    printf("You rolled: %d\n", rolled);

    if (rolled == point) {
      return true; // The player wins if he or she rolls the point again.
    } else if (rolled == 7) {
      return false; // The player loses by rolling 7.
    }

    // Any other roll is ignored and the game continues.
  }
}

int main(void) {
  srand((unsigned) time(NULL));

  int wins = 0;
  int losses = 0;

  while (true) {
    bool won = play_game();
    if (won) {
      printf("You win!\n");
      wins++;
    } else {
      printf("You lose!\n");
      losses++;
    }

    printf("\nPlay again? ");
    char c = (char)getchar();
    getchar(); // Read the newline.

    if (toupper(c) != 'Y') { break; }
  }

  printf("\nWins: %d, Losses: %d\n", wins, losses);
  return 0;
}
