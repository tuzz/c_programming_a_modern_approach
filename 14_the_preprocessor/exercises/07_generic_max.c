#define GENERIC_MAX(type)                \
static type type##_max(type x, type y) { \
  return x > y ? x : y;                  \
}

GENERIC_MAX(long)
// a) Macro expands to:
// static long long_max(long x, long y) {
//   return x > y ? x : y;
// }

// GENERIC_MAX(unsigned long)
// b) Macro would expand to "unsigned long_max" which isn't a valid function name.

// c) We can use a typedef to define a new type that doesn't contain whitespace.
typedef unsigned long ulong;
GENERIC_MAX(ulong)

int main(void) {
  return 0;
}
