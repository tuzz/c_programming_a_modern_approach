#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
  char c, first_letter;
  char last_name[20];
  int i = 0;
  printf("Enter a first and last name: ");

  // Read optional whitespace.
  while ((c = (char)getchar()) == ' ' || c == '\t' || c == '\n') {}

  // Save the first_letter for printing at the end,
  first_letter = (char)toupper(c);

  // Read the first name.
  while ((c = (char)getchar()) != ' ' && c != '\t' && c != '\n') {}

  // Read optional whitespace.
  while ((c = (char)getchar()) == ' ' || c == '\t' || c == '\n') {}

  // Store the first letter of the last name.
  last_name[i++] = (char)toupper(c);

  // Read the rest of the letters of the last name.
  while ((c = (char)getchar()) != ' ' && c != '\t' && c != '\n') { last_name[i++] = c; }

  // Read whitespace (or anything else) until a newline.
  while (c != '\n') { c = (char)getchar(); }

  printf("You entered the name: ");
  for (int j = 0; j < i; j++) {
    putchar(last_name[j]);
  }

  printf(", %c.\n", first_letter);
  return 0;
}
