#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: xor <input> <output>\n");
    exit(EXIT_FAILURE);
  }

  FILE *input = fopen(argv[1], "rb");
  if (!input) {
    fprintf(stderr, "Failed to open %s for reading.\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  FILE *output = fopen(argv[2], "wb");
  if (!output) {
    fprintf(stderr, "Failed to open %s for writing.\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  int ch = 0;

  while ((ch = getc(input)) != EOF) {
    if (putc(ch ^ KEY, output) == EOF) {
      fprintf(stderr, "Failed to write %s.\n", argv[2]);
      fclose(input);
      fclose(output);
      exit(EXIT_FAILURE);
    }
  }

  if (ferror(input)) {
    fprintf(stderr, "Failed to read %s.\n", argv[1]);
    fclose(input);
    fclose(output);
    exit(EXIT_FAILURE);
  }

  fclose(input);
  fclose(output);
  return 0;
}
