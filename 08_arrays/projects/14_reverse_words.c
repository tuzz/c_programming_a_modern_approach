#include <stdio.h>
#include <stdbool.h>

int main(void) {
  char array[100];
  int i = 0;
  char c;

  // Add non-terminal characters to an array.
  while ((c = (char)getchar()) != '.' && c != '?' && c != '!') { array[i++] = c; }
  int end_of_word = i;

  // Iterate backwards through the sentence.
  for (int j = i; j > 0; j--) {
    // Iterate forwards through whitespace-delimited words and print them.
    if (array[j - 1] == ' ') {
      for (int k = j; k < end_of_word; k++) { putchar(array[k]); }
      putchar(' ');
      end_of_word = j - 1;
    }
  }

  // Print the first word followed by the terminal character.
  for (int k = 0; k < end_of_word; k++) { putchar(array[k]); }
  printf("%c\n", c);
  return 0;
}
