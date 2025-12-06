#include <stdio.h>

int main(void) {
  printf("%6d,%4d\n", 86, 1040);     // a) Produces "    86,1040"
  printf("%12.5e\n", (double)30253); // b) Produces " 3.02530e+04"
  printf("%.4f\n", 83.162);          // c) Produces "83.1620"
  printf("%-6.2g\n", .0000009979);   // d) Produces "1e-06"
  return 0;
}
