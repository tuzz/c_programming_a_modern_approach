#include <stdio.h>
#include <string.h>

int main(void) {
  char s1[50] = "";
  char s2[50] = "";

  strcpy(s1, "computer");
  printf("s1: %s\n", s1);
  // s1 is now "computer"

  strcpy(s2, "science");
  printf("s2: %s\n", s2);
  // s2 is now "science"

  // "computer" is lexically before "science" so the consequent will be evaluated.
  if (strcmp(s1, s2) < 0) {
    strcat(s1, s2);
    printf("s1: %s\n", s1);
    // s1 is now "computerscience"
  } else {
    strcat(s2, s1);
  }

  s1[strlen(s1) - 6] = '\0';
  printf("s1: %s\n", s1);
  // s1 is now "computers"

  return 0;
}
