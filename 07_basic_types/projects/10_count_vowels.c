#include <stdio.h>
#include <ctype.h>

int main(void) {
  printf("Enter a sentence: ");

  char c;
  int count = 0;

  while ((c = (char)getchar()) != '\n') {
    switch (toupper(c)) {
      case 'A': case 'E': case 'I': case 'O': case 'U':
        count++;
        break;
      default:
        break;
    }
  }

  printf("Your sentence contains %d vowels.\n", count);
  return 0;
}
