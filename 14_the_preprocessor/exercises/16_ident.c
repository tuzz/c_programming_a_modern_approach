#include <stdio.h>

#define IDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)

IDENT(foo)
// The line above will first be expanded to PRAGMA(ident "foo")
// It will then be expanded to _Pragma("ident \"foo\"")
// Which is equivalent to #pragma ident "foo"

int main(void) {
  return 0;
}
