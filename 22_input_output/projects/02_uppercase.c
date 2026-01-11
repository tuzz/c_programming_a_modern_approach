#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int ch;

  if (argc != 2) {
    fprintf(stderr, "Usage: uppercase <filename>\n");
    exit(EXIT_FAILURE);
  }

  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Failed to open file.\n");
    exit(EXIT_FAILURE);
  }

  while ((ch = getc(fp)) != EOF) {
    putchar(toupper(ch));
  }

  fclose(fp);
  return 0;
}
