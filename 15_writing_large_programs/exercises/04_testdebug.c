#include <stdio.h>

#define DEBUG
#include "04_debug.h"

int main(void) {
  int i = 1, j = 2, k = 3;

#ifdef DEBUG
  printf("Output if DEBUG is defined:\n");
#else
  printf("Output if DEBUG is not defined:\n");
#endif

  PRINT_DEBUG(i);
  PRINT_DEBUG(j);
  PRINT_DEBUG(k);
  PRINT_DEBUG(i + j);
  PRINT_DEBUG(2 * i + j - k);

  return 0;
}

// a) The output is the following when the program is executed:
// Output if DEBUG is defined:
// Value of i: 1
// Value of j: 2
// Value of k: 3
// Value of i + j: 3
// Value of 2 * i + j - k: 1
//
// b) The output is the following when the program is executed
// Output if DEBUG is not defined:
//
// c) The output is different in parts a) and b) because:
//   i) The printf statement in this file conditionally depends on DEBUG
//   ii) The PRINT_DEBUG macro in debug.h conditionally depends on DEBUG. If
//       the DEBUG macro is not defined then PRINT_DEBUG expands to nothing.
//
// d) Yes, it is necessary for the DEBUG macro to be defined before including
// debug.h because the preprocessor is stateful and expands macros in order. The
// #include directive effectively copies debug.h into this file so it must come
// after the DEBUG macro was defined for it to have the desired effect.
