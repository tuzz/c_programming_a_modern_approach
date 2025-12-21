#include <stdio.h>

int main(void) {
  char s[] = "Hsjodi", *p;

  for (p = s; *p; p++) {
    --*p;
  }

  // Prints "Grinch" because each character's value is decremented by 1.
  puts(s);

  return 0;
}
