#include <stdio.h>
#include <ctype.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  char message[100];
  printf("Enter message: ");

  char c;
  for (size_t i = 0; i < ARRAY_COUNT(message); i++) {
    c = (char)getchar();
    if (c == '\n') { break; }
    message[i] = c;
  }

  printf("In B1FF-speak: ");

  for (size_t i = 0; i < ARRAY_COUNT(message); i++) {
    c = message[i];
    if (!c) { break; }

    c = (char)toupper(c);
    switch (c) {
      case 'A': putchar('4'); break;
      case 'B': putchar('8'); break;
      case 'E': putchar('3'); break;
      case 'I': putchar('1'); break;
      case 'O': putchar('0'); break;
      case 'S': putchar('5'); break;
      default:  putchar(c);   break;
    }
  }

  for (int i = 0; i < 10; i++) {
    putchar('!');
  }

  putchar('\n');
  return 0;
}
