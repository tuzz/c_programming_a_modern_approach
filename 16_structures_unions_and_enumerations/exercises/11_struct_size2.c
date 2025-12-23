#include <stdio.h>

#pragma pack(1) // Assume that the compiler leaves no "holes" between members.

static union {
  double a;             // 8 bytes
  struct {
    char b[4];          // 4 bytes
    double c;           // 8 bytes
    int d;              // 4 bytes
  } e;                  // -- struct is 16 bytes total   <-- union is 16 bytes total
  char f[4];            // 4 bytes
} u;

// 16 bytes total for the union

int main(void) {
  printf("%lu\n", sizeof(u));
  return 0;
}
