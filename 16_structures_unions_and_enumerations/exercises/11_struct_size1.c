#include <stdio.h>

#pragma pack(1) // Assume that the compiler leaves no "holes" between members.

static struct {
  double a;            // 8 bytes
  union {
    char b[4];         // 4 bytes
    double c;          // 8 bytes     <-- union is 8 bytes total
    int d;             // 4 bytes
  } e;
  char f[4];           // 4 bytes
} s;

// 8 + 8 + 4 = 20 bytes total for the struct

int main(void) {
  printf("%lu\n", sizeof(s));
  return 0;
}
