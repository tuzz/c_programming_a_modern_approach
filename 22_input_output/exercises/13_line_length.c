#include <stdio.h>
#include <stdlib.h>

int line_length(const char *filename, int n) {
  FILE *fp = fopen(filename, "r"); // Open as text.

  if (!fp) {
    fprintf(stderr, "Failed to open file.\n");
    exit(EXIT_FAILURE);
  }

  for (int line = 1; line < n; line++) {
    fscanf(fp, "%*[^\n]");
    fgetc(fp);
  }

  int ch, length = 0;
  while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
    length++;
  }

  fclose(fp);
  return length;
}

int main(void) {
  for (int n = 1; n <= 35; n++) {
    int length = line_length("22_input_output/exercises/13_line_length.c", n);
    printf("Line %d of this file has length %d.\n", n, length);
    if (n == length) { printf("EUREKA!\n"); }
  }

  return 0;
}
