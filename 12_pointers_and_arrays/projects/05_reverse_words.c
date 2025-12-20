#include <stdio.h>
#include <stdbool.h>

int main(void) {
  char array[100], c, *p = array;

  // Add non-terminal characters to an array.
  while ((c = (char)getchar()) != '.' && c != '?' && c != '!') { *p++ = c; }
  char *end_of_word = p;

  // Iterate backwards through the sentence.
  for (p--; p >= array; p--) {
    // Iterate forwards through whitespace-delimited words and print them.
    if (*(p - 1) == ' ') {
      for (char *q = p; q < end_of_word; q++) { putchar(*q); }
      putchar(' ');
      end_of_word = p - 1;
    }
  }

  // Print the first word followed by the terminal character.
  for (*p = 0; p < end_of_word; p++) { putchar(*p); }
  printf("%c\n", c);
  return 0;
}
