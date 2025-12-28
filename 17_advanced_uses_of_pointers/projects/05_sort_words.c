#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD 20
#define MAX_WORDS 10

static int alphabetically(const void *a, const void *b) {
  const char *const *string1 = a;
  const char *const *string2 = b;

  return strcmp(*string1, *string2);
}

int main(void) {
  char *words[MAX_WORDS] = {0};
  int i = 0;

  while (true) {
    char word[MAX_WORD + 2]; // Includes "\n\0"
    printf("Enter word: ");
    fgets(word, MAX_WORD, stdin);
    if (word[0] == '\n') { break; }

    if (i == MAX_WORDS) {
      printf("Cannot add more words, breaking.\n");
      break;
    }

    unsigned long word_len = strlen(word);
    word[word_len - 1] = '\0'; // Remove '\n'

    words[i] = malloc(word_len - 1);
    if (!words[i]) {
      printf("Failed to allocate memory for word, breaking.\n");
      break;
    }

    strcpy(words[i], word);
    i++;
  }

  qsort(words, (size_t)i, sizeof(char *), alphabetically);
  printf("In sorted order: ");

  for (int j = 0; j < i; j++) {
    printf("%s ", words[j]);
  }
  printf("\n");

  return 0;
}
