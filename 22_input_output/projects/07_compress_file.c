#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: compress_file <filename>\n");
    exit(EXIT_FAILURE);
  }

  FILE *input = fopen(argv[1], "rb");
  if (!input) {
    fprintf(stderr, "Failed to open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  size_t len = strlen(argv[1]) + 4;
  char *filename = calloc(1, len);
  sprintf(filename, "%s.rle", argv[1]);

  FILE *output = fopen(filename, "wb");
  if (!output) {
    fprintf(stderr, "Failed to open %s\n", filename);
    fclose(input);
    free(filename);
    exit(EXIT_FAILURE);
  }

  int ch = getc(input);
  int previous = ch;
  int count = 0;
  bool write_error = false;

  while (ch != EOF) {
    if (ch == previous && count != UCHAR_MAX) {
      count++;
    } else {
      write_error |= putc(count, output) == EOF;
      write_error |= putc(previous, output) == EOF;
      if (write_error) { break; }

      count = 1;
      previous = ch;
    }

    ch = getc(input);
  }

  if (count != 0) {
    write_error |= putc(count, output) == EOF;
    write_error |= putc(previous, output) == EOF;
  }

  if (ferror(input)) {
    fprintf(stderr, "Failed to read %s\n", argv[1]);
    fclose(input);
    fclose(output);
    free(filename);
    exit(EXIT_FAILURE);
  }

  if (write_error) {
    fprintf(stderr, "Failed to write %s\n", filename);
    fclose(input);
    fclose(output);
    free(filename);
    exit(EXIT_FAILURE);
  }

  fclose(input);
  fclose(output);
  free(filename);
  return 0;
}
