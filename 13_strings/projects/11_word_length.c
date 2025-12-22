#include <stdio.h>
#include <stdbool.h>

static double compute_average_word_length(const char *sentence) {
  bool is_word = false;
  bool was_word = false;
  int num_words = 0;
  int text_length = 0;
  const char *s = sentence;

  while (*s) {
    was_word = is_word;
    is_word = *s != ' ' && *s != '\t';

    if (!was_word && is_word) { num_words++; }
    if (is_word) { text_length++; }

    s++;
  }

  return (double)text_length / num_words;
}

int main(void) {
  char c, sentence[500] = "", *p = sentence;
  printf("Enter a sentence: ");

  while ((c = (char)getchar()) != '\n') { *p++ = c; }
  printf("Average word length: %.1f\n", compute_average_word_length(sentence));

  return 0;
}
