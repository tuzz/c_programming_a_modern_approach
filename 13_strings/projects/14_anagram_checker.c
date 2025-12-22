#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

static bool are_anagrams(const char *word1, const char *word2) {
  int tally[26] = {0};

  for (const char *w = word1; *w; w++) {
    if (isalpha(*w)) { tally[tolower(*w) - 'a']++; }
  }

  for (const char *w = word2; *w; w++) {
    if (isalpha(*w)) { tally[tolower(*w) - 'a']--; }
  }

  for (size_t i = 0; i < ARRAY_COUNT(tally); i++) {
    if (tally[i] != 0) {
      return false;
    }
  }

  return true;
}

int main(void) {
  char word1[50] = "";
  char word2[50] = "";

  printf("Enter first word: ");
  fgets(word1, ARRAY_COUNT(word1), stdin);

  printf("Enter second word: ");
  fgets(word2, ARRAY_COUNT(word2), stdin);

  if (are_anagrams(word1, word2)) {
    printf("The words are anagrams.\n");
  } else {
    printf("The words are not anagrams.\n");
  }

  return 0;
}
