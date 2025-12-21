#include <stdio.h>
#include <string.h>

int main(void) {
  char str[50] = "";

  strcpy(str, "tire-bouchon");
  printf("%s\n", str);
  // str is now "tire-bouchon"

  strcpy(&str[4], "d-or-wi");
  printf("%s\n", str);
  // str is now "tired-or-wi"

  strcat(str, "red?");
  printf("%s\n", str);
  // str is now "tired-or-wired"

  return 0;
}
