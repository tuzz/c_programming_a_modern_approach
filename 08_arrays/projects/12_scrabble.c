#include <stdio.h>
#include <ctype.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
                 // A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q   R  S  T  U  V  W  X  Y  Z
  int values[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

  char c;
  printf("Enter a word: ");
  int sum = 0;

  while ((c = (char)getchar()) != '\n') {
    c = (char)toupper(c);
    size_t index = (size_t)c - 'A';

    if (index < ARRAY_COUNT(values)) {
      sum += values[index];
    }
  }

  printf("Scrabble value: %d\n", sum);
  return 0;
}
