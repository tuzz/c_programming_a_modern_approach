#include <stdio.h>
#include <ctype.h>

int main(void) {
  int hours, minutes;
  printf("Enter a 12-hour time: ");
  scanf("%d:%d", &hours, &minutes);

  char c;
  while ((c = (char)getchar()) == ' ' || c == '\t' || c == '\n') {}
  if (toupper(c) == 'P') { hours += 12; }

  printf("Equivalent 24-hour time: %d:%.2d\n", hours, minutes);
  return 0;
}
