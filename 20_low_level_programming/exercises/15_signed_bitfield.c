#include <stdio.h>

struct {
  int flag: 1;
} s;

int main(void) {
  s.flag = 1;

  // The reason this prints -1 is because we are using a signed integer for the flag.
  // Normally, a signed integer stores the sign in the most significant bit.
  // To fix it, we can use an unsigned int instead of an int for the struct member.
  printf("%d\n", s.flag);
  return 0;
}
