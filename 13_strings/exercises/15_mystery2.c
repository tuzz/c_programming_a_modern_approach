#include <stdio.h>

static int f(char *s, char *t) {
  char *p1, *p2;

  // Iterate through string s.
  for (p1 = s; *p1; p1++) {
    // Iterate through string t.
    for (p2 = t; *p2; p2++)
      // Break if the characters are the same.
      if (*p1 == *p2) break;

    // Break if we reached the end of the t.
    if (*p2 == '\0') break;
  }

  // Return the number of characters that p1 is after s.
  return (int)(p1 - s);
}

int main(void) {
  // a) Prints "3"
  printf("%d\n", f("abcd", "babc"));

  // b) Prints "0"
  printf("%d\n", f("abcd", "bcd"));

  // c) In general, f finds the first character that appears in s but not in t.
  //
  // It goes through each character of s and checks if it appears anywhere in t.
  // If it does then we break the inner loop and check the next character in s.
  // If it doesn't then we reach the end of string t and break the outer loop.
  //
  // We then return the difference between p1 and s which is the index position
  // of the character that was not found in t. If all characters from s appear
  // in t then f returns the length of string s, i.e. the index after s.
  printf("%d\n", f("abcd", "abcd"));

  return 0;
}
