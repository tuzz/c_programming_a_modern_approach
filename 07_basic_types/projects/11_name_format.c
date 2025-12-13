#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
  char c, first_letter;
  printf("Enter a first and last name: ");

  // Read optional whitespace.
  while ((c = (char)getchar()) == ' ' || c == '\t' || c == '\n') {}

  // Save the first_letter for printing at the end,
  first_letter = (char)toupper(c);

  // Read the first name.
  while ((c = (char)getchar()) != ' ' && c != '\t' && c != '\n') {}

  // Read optional whitespace.
  while ((c = (char)getchar()) == ' ' || c == '\t' || c == '\n') {}

  // Print the first letter of the last name.
  putchar(toupper(c));

  // Read and print the rest of the letters of the last name.
  while ((c = (char)getchar()) != ' ' && c != '\t' && c != '\n') { putchar(c); }

  // Read whitespace (or anything else) until a newline.
  while (c != '\n') { c = (char)getchar(); }

  printf(", %c\n", first_letter);
  return 0;
}
