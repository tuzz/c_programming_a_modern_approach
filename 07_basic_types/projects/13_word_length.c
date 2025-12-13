#include <stdio.h>
#include <stdbool.h>

int main(void) {
  char c;
  printf("Enter a sentence: ");

  bool is_word = false;
  bool was_word = false;
  int num_words = 0;
  int text_length = 0;

  while ((c = (char)getchar()) != '\n') {
    was_word = is_word;
    is_word = c != ' ' && c != '\t';

    if (!was_word && is_word) { num_words++; }
    if (is_word) { text_length++; }
  }

  float average_word_length = (float)text_length / num_words;
  printf("Average word length: %.1f\n", (double)average_word_length);

  return 0;
}
