#include <stdio.h>

#define M 10

int main(void) {
  // a) test passes because 10 is truthy
  #if M
    printf("here1\n");
  #endif

  // b) test passes because M is defined
  #ifdef M
    printf("here2\n");
  #endif

  // c) test fails because M is defined              <------ fails
  #ifndef M
    printf("here3\n");
  #endif

  // d) test passes because M is defined
  #if defined(M)
    printf("here4\n");
  #endif

  // d) test fails because M is defined              <------ fails
  #if !defined(M)
    printf("here5\n");
  #endif

  return 0;
}
