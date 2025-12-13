#include <stdio.h>

int main(void) {
  typedef char Int8;
  typedef short Int16;
  typedef int Int32;

  printf("sizeof(Int8) == %lu\n", sizeof(Int8));
  printf("sizeof(Int16) == %lu\n", sizeof(Int16));
  printf("sizeof(Int32) == %lu\n", sizeof(Int32));

  return 0;
}
