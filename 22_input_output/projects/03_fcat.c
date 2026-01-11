#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp = NULL;
  char buffer[8192];
  size_t bytes_read = 0;

  if (argc < 2) {
    printf("usage: fcat filenames\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "rb")) == NULL) {
      fprintf(stderr, "Failed to open %s\n", argv[i]);
      continue;
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp))) {
      if (fwrite(buffer, 1, bytes_read, stdout) != bytes_read) {
        fprintf(stderr, "Error writing to stdout\n");
        break;
      }
    }

    if (ferror(fp)) {
      fprintf(stderr, "Error reading %s\n", argv[i]);
    }

    fclose(fp);
  }

  return 0;
}
