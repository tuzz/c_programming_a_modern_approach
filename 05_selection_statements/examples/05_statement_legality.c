#include <stdio.h>

int main(void) {
  int n = 5;

  // The following statement is legal but my compiler warns about it:
  // > comparisons like 'X<=Y<=Z' don't have their mathematical meaning
  //
  // if (n >= 1 <= 10)
  //   printf("n is between 1 and 10\n");

  // The problem is that n >= 1 evaluates to either 0 or 1 and in this case,
  // the value is always less than or equal to 10 so the result is always true.
  //
  // The compiler helpfully raises another warning about this as well:
  // > result of comparison of constant 10 with boolean expression is always true

  // The programmer intended to write the following:
  if (n >= 1 && n <= 10) {
    printf("n is between 1 and 10\n");
  }
}
