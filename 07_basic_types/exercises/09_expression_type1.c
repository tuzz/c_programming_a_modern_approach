#include <stdio.h>

int main(void) {
  int i = 0;
  int j = 0;

  // The type of the expression is int. First i / j will be evaluated. Since
  // they are both int then no type conversion needs to occur and the result
  // will be an int as well. Then we add an int to a char. In this case, the
  // operands will be be converted to the smallest type that accommodates both
  // which is int. There char will be promoted to int and the result is an int.
  printf("%d\n", i / j + 'a');

  return 0;
}
