#include <stdio.h>
#include <ctype.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  int tally[26] = {0};
  char c;

  printf("Enter first word: ");
  while ((c = (char)getchar()) != '\n') {
    if (isalpha(c)) { tally[tolower(c) - 'a']++; }
  }

  printf("Enter second word: ");
  while ((c = (char)getchar()) != '\n') {
    if (isalpha(c)) { tally[tolower(c) - 'a']--; }
  }

  for (size_t i = 0; i < ARRAY_COUNT(tally); i++) {
    if (tally[i] != 0) {
      printf("The words are not anagrams.\n");
      return 0;
    }
  }

  printf("The words are anagrams.\n");
  return 0;
}
