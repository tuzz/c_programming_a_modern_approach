#include <stdio.h>
#include <stdlib.h>

char *my_fgets(char *string, size_t capacity, FILE *stream) {
  if (capacity == 0) { return NULL; } // Too small to store null character.

  size_t length = 0;
  int ch = 0;

  // fgets reads characters until it reaches the first newline character or
  // the size of the string minus one has been read.
  while (ch != '\n' && length < capacity - 1) {
    ch = getc(stream);

    // fgets returns a null pointer if it reaches the end of the input stream
    // before storing any characters or a read error occurs.
    if (ch == EOF) {
      if (length == 0 || ferror(stream)) {
        return NULL;
      } else {
        break;
      }
    }

    string[length++] = (char)ch;
  }

  string[length] = '\0';
  return string;
}

int my_fputs(const char *string, FILE *stream) {
  const char *p = string;

  while (*p) {
    if (putc(*p, stream) == EOF) {
      // fputs returns EOF if a write error occurs.
      return EOF;
    }

    p++;
  }

  // fputs returns a non-negative number on success.
  return 0;
}

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  char string[50];
  FILE *file = fopen("22_input_output/exercises/14_fgets.c", "r");

  if (!file) {
    fprintf(stderr, "Failed to open file.\n");
    exit(EXIT_FAILURE);
  }

  if (!my_fgets(string, ARRAY_COUNT(string), file)) {
    fprintf(stderr, "Failed to read line of file.\n");
    exit(EXIT_FAILURE);
  }

  printf("First line of this file: %s", string);

  fclose(file);
  file = fopen("output.txt", "w");

  if (!file) {
    fprintf(stderr, "Failed to open file.\n");
    exit(EXIT_FAILURE);
  }

  if (my_fputs(string, file) == EOF) {
    fprintf(stderr, "Failed to write line to file.\n");
    exit(EXIT_FAILURE);
  }

  fclose(file);
  return 0;
}
