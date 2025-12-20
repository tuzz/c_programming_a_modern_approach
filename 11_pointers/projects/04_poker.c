#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_CARDS 5
#define TWO_RANK 0
#define TEN_RANK 8
#define ACE_RANK 12

void read_cards(int hand[NUM_CARDS][2]);
bool card_exists(int hand[NUM_CARDS][2], int cards_read, int rank, int suit);
void analyze_hand(int hand[NUM_CARDS][2], bool *ten_low, bool *straight, bool *flush, bool *four, bool *three, int *pairs);
void selection_sort_by_rank(int hand[NUM_CARDS][2], int n);
void print_result(bool ten_low, bool straight, bool flush, bool four, bool three, int pairs);

int main(void) {
  int hand[NUM_CARDS][2];
  bool ten_low, straight, flush, four, three;
  int pairs;

  for (;;) {
    read_cards(hand);
    analyze_hand(hand, &ten_low, &straight, &flush, &four, &three, &pairs);
    print_result(ten_low, straight, flush, four, three, pairs);
  }
}

void read_cards(int hand[NUM_CARDS][2]) {
  char ch, rank_ch, suit_ch;
  int rank = -1, suit = -1;
  bool bad_card;
  int cards_read = 0;

  for (int i = 0; i < NUM_CARDS; i++) {
    hand[i][0] = 0;
    hand[i][1] = 0;
  }

  while (cards_read < NUM_CARDS) {
    bad_card = false;

    printf("Enter a card: ");

    rank_ch = (char)getchar();
    switch (rank_ch) {
      case '0':           exit(EXIT_SUCCESS);
      case '2':           rank = 0; break;
      case '3':           rank = 1; break;
      case '4':           rank = 2; break;
      case '5':           rank = 3; break;
      case '6':           rank = 4; break;
      case '7':           rank = 5; break;
      case '8':           rank = 6; break;
      case '9':           rank = 7; break;
      case 't': case 'T': rank = 8; break;
      case 'j': case 'J': rank = 9; break;
      case 'q': case 'Q': rank = 10; break;
      case 'k': case 'K': rank = 11; break;
      case 'a': case 'A': rank = 12; break;
      default:            bad_card = true;
    }

    suit_ch = (char)getchar();
    switch (suit_ch) {
      case 'c': case 'C': suit = 0; break;
      case 'd': case 'D': suit = 1; break;
      case 'h': case 'H': suit = 2; break;
      case 's': case 'S': suit = 3; break;
      default:            bad_card = true;
    }

    while ((ch = (char)getchar()) != '\n') {
      if (ch != ' ') { bad_card = true; }
    }

    if (bad_card) {
      printf("Bad card; ignored.\n");
    } else if (card_exists(hand, cards_read, rank, suit)) {
      printf("Duplicate card; ignored.\n");
    } else {
      hand[cards_read][0] = rank;
      hand[cards_read][1] = suit;
      cards_read++;
    }
  }
}

bool card_exists(int hand[NUM_CARDS][2], int cards_read, int rank, int suit) {
  for (int i = 0; i < cards_read; i++) {
    if (hand[i][0] == rank && hand[i][1] == suit) {
      return true;
    }
  }

  return false;
}

void analyze_hand(int hand[NUM_CARDS][2], bool *ten_low, bool *straight, bool *flush, bool *four, bool *three, int *pairs) {
  selection_sort_by_rank(hand, NUM_CARDS);
  *ten_low = hand[0][0] == TEN_RANK;

  *flush = true;
  for (int i = 1; i < NUM_CARDS; i++) {
    if (hand[i][1] != hand[0][1]) {
      *flush = false;
      break;
    }
  }

  *straight = true;
  for (int i = 1; i < NUM_CARDS; i++) {
    if (i == NUM_CARDS - 1 && hand[i][0] == ACE_RANK && hand[0][0] == TWO_RANK) {
      break;
    } else if (hand[i][0] - hand[i - 1][0] != 1) {
      *straight = false;
      break;
    }
  }

  *four = false;
  *three = false;
  *pairs = 0;
  int prev_rank = hand[0][0];
  int matches = 1;
  for (int i = 1; i < NUM_CARDS; i++) {
    if (hand[i][0] == prev_rank) {
      matches++;
    } else {
      switch (matches) {
        case 2: *pairs += 1;   break;
        case 3: *three = true; break;
        case 4: *four = true;  break;
        default:               break;
      }

      matches = 1;
      prev_rank = hand[i][0];
    }
  }
  switch (matches) {
    case 2: *pairs += 1;   break;
    case 3: *three = true; break;
    case 4: *four = true;  break;
    default:               break;
  }
}

void selection_sort_by_rank(int hand[NUM_CARDS][2], int n) {
  if (n <= 1) { return; }

  int largest = hand[0][0];
  int largest_i = 0;

  for (int i = 1; i < n; i++) {
    if (hand[i][0] > largest) {
      largest = hand[i][0];
      largest_i = i;
    }
  }

  int tmp_rank = hand[n - 1][0];
  int tmp_suit = hand[n - 1][1];
  hand[n - 1][0] = hand[largest_i][0];
  hand[n - 1][1] = hand[largest_i][1];
  hand[largest_i][0] = tmp_rank;
  hand[largest_i][1] = tmp_suit;

  selection_sort_by_rank(hand, n - 1);
}

void print_result(bool ten_low, bool straight, bool flush, bool four, bool three, int pairs) {
  if (straight && flush && ten_low) { printf("Royal flush"); }
  else if (straight && flush)       { printf("Straight flush"); }
  else if (four)                    { printf("Four of a kind"); }
  else if (three && pairs == 1)     { printf("Full house"); }
  else if (flush)                   { printf("Flush"); }
  else if (straight)                { printf("Straight"); }
  else if (three)                   { printf("Three of a kind"); }
  else if (pairs == 2)              { printf("Two pairs"); }
  else if (pairs == 1)              { printf("Pair"); }
  else                              { printf("High card"); }

  printf("\n\n");
}
