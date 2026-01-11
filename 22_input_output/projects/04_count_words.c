#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: count_words <filename>\n");
    exit(EXIT_FAILURE);
  }

  FILE *file = fopen(argv[1], "r");

  if (!file) {
    fprintf(stderr, "Failed to open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  size_t count = 0;
  int ch;
  bool is_word = false;

  while ((ch = getc(file)) != EOF) {
    if (isspace(ch)) {
      is_word = false;
    } else if (!is_word) {
      is_word = true;
      count++;
    }
  }

  if (ferror(file)) {
    fprintf(stderr, "Error reading %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  printf("Number of words: %zu\n", count);
  fclose(file);

  return 0;
}
