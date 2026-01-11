#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: uncompress_file <filename>\n");
    exit(EXIT_FAILURE);
  }

  char *extension = NULL;
  for (char *p = argv[1]; *p; p++) {
    if (*p == '.') { extension = p; }
  }

  if (!extension || strcmp(extension, ".rle") != 0) {
    fprintf(stderr, "%s does not end with .rle\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  FILE *input = fopen(argv[1], "rb");
  if (!input) {
    fprintf(stderr, "Failed to open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  size_t len = strlen(argv[1]) + 16;
  char *filename = calloc(1, len);
  sprintf(filename, "%s.uncompress_file", argv[1]);

  FILE *output = fopen(filename, "wb");
  if (!output) {
    fprintf(stderr, "Failed to open %s\n", filename);
    fclose(input);
    free(filename);
    exit(EXIT_FAILURE);
  }

  int count = 0;
  int ch = 0;
  bool write_error = false;

  while ((count = getc(input)) != EOF && !write_error) {
    if ((ch = getc(input)) == EOF) {
      fprintf(stderr, "Input file is malformed %s\n", argv[1]);
      fclose(input);
      fclose(output);
      free(filename);
      exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
      write_error |= putc(ch, output) == EOF;
    }
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
