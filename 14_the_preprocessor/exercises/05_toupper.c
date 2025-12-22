#include <stdio.h>
#include <string.h>

#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))

int main(void) {
  char s[50];
  int i;

  // a) Macro expands to ('a'<=(s[++i])&&(s[++i])<='z'?(s[++i])-'a'+'A':(s[++i]))
  // So i is incremented three times before indexing into s. Therefore, prints "D".
  strcpy(s, "abcd");
  i = 0;
  putchar(TOUPPER(s[++i]));

  // b) Macro expands to ('a'<=(s[++i])&&(s[++i])<='z'?(s[++i])-'a'+'A':(s[++i]))
  // In this case, the condition short circuits so i is incremented twice. Prints "2".
  strcpy(s, "0123");
  i = 0;
  putchar(TOUPPER(s[++i]));

  return 0;
}
