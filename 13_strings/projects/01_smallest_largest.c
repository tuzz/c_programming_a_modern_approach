#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

int main(void) {
  char smallest_word[MAX_LEN + 1] = "";
  char largest_word[MAX_LEN + 1] = "";
  char current_word[MAX_LEN + 1] = "";

  while (strlen(current_word) != 4) {
    printf("Enter word: ");
    scanf("%20s", current_word);

    if (*smallest_word == '\0' || strcmp(current_word, smallest_word) < 0) {
      strcpy(smallest_word, current_word);
    }

    if (*largest_word == '\0' || strcmp(current_word, largest_word) > 0) {
      strcpy(largest_word, current_word);
    }
  }

  printf("Smallest word: %s\n", smallest_word);
  printf("Largest word: %s\n", largest_word);

  return 0;
}
