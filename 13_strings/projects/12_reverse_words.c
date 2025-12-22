#include <stdio.h>
#include <stdbool.h>

int main(void) {
  char words[30][20] = {0};
  int word_index = 0;
  char c;
  int char_index = 0;

  while ((c = (char)getchar()) != '.' && c != '?' && c != '!') {
    if (c == ' ' && char_index > 0) {
      word_index++;
      char_index = 0;
    } else {
      words[word_index][char_index] = c;
      char_index++;
    }
  }

  for (int i = word_index; i >= 0; i--) {
    printf("%s", words[i]);
    if (i > 0) { putchar(' '); }
  }
  printf("%c\n", c);

  return 0;
}
