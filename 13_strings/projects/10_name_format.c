#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

static void reverse_name(char *name) {
  char c, *n = name;
  char reversed[100] = "", *r = reversed;

  // Read optional whitespace.
  while ((c = *n++) == ' ' || c == '\t' || c == '\n') {}

  // Save the first_letter for storing at the end,
  char first_letter = (char)toupper(c);

  // Read the first name.
  while ((c = *n++) != ' ' && c != '\t' && c != '\n') {}

  // Read optional whitespace.
  while ((c = *n++) == ' ' || c == '\t' || c == '\n') {}

  // Store the first letter of the last name.
  *r++ = (char)toupper(c);

  // Read and store the rest of the letters of the last name.
  while ((c = *n++) != ' ' && c != '\t' && c != '\n' && c != '\0') { *r++ = c; }

  sprintf(r, ", %c.", first_letter);
  strcpy(name, reversed);
}

int main(void) {
  printf("Enter a first and last name: ");
  char c, name[100] = "", *p = name;

  while ((c = (char)getchar()) != '\n') { *p++ = c; }
  *p = '\0';

  reverse_name(name);
  printf("%s\n", name);

  return 0;
}
