#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 10

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: display <filename>\n");
    exit(EXIT_FAILURE);
  }

  FILE *file = fopen(argv[1], "rb");
  if (!file) {
    fprintf(stderr, "Failed to open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  unsigned char bytes[N] = {0};
  size_t num_read = 0;
  size_t offset = 0;

  printf("Offset              Bytes              Characters\n");
  printf("------  -----------------------------  ----------\n");

  while ((num_read = fread(bytes, 1, N, file)) != 0) {
    printf("%6zu  ", offset);

    for (size_t i = 0; i < num_read; i++) {
      printf("%02X ", bytes[i]);
    }

    for (size_t i = num_read; i < N; i++) {
      printf("   ");
    }

    putchar(' ');
    for (size_t i = 0; i < num_read; i++) {
      if (isprint(bytes[i])) {
        putchar(bytes[i]);
      } else {
        putchar('.');
      }
    }

    putchar('\n');
    offset += N;
  }

  if (ferror(file)) {
    fprintf(stderr, "Failed to read %s\n", argv[1]);
    fclose(file);
    exit(EXIT_FAILURE);
  }

  fclose(file);
  return 0;
}
