#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: count_lines <filename>\n");
    exit(EXIT_FAILURE);
  }

  FILE *file = fopen(argv[1], "r");

  if (!file) {
    fprintf(stderr, "Failed to open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  size_t count = 0;
  int ch;

  while ((ch = getc(file)) != EOF) {
    if (ch == '\n') { count++; }
  }

  if (ferror(file)) {
    fprintf(stderr, "Error reading %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  printf("Number of lines: %zu\n", count);
  fclose(file);

  return 0;
}
