#include <stdio.h>
#include <ctype.h>

static int compute_vowel_count(const char *sentence) {
  int count = 0;

  while (*sentence) {
    switch (toupper(*sentence)) {
      case 'A': case 'E': case 'I': case 'O': case 'U':
        count++;
        break;
      default:
        break;
    }

    sentence++;
  }

  return count;
}

int main(void) {
  printf("Enter a sentence: ");
  char c, sentence[100] = "", *p = sentence;

  while ((c = (char)getchar()) != '\n') { *p++ = c; }

  printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));
  return 0;
}
