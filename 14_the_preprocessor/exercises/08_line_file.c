#include <stdio.h>

#define LINE_FILE "Line " STRING(__LINE__) " of file " __FILE__
#define STRING(x) STRING_(x) // Expand x before stringizing it.
#define STRING_(x) #x

int main(void) {
  const char *str = LINE_FILE;
  printf("%s\n", str);
  return 0;
}
