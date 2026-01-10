#include <stddef.h>
#include <stdio.h>

struct s {
  char a;
  int b[2];
  float c;
};

int main(void) {
  struct s s;

  printf("The size of member a is %lu and its offset is %lu.\n", sizeof(s.a), offsetof(struct s, a));
  printf("The size of member b is %lu and its offset is %lu.\n", sizeof(s.b), offsetof(struct s, b));
  printf("The size of member c is %lu and its offset is %lu.\n", sizeof(s.c), offsetof(struct s, c));
  printf("The size of struct s is %lu.\n", sizeof(struct s));

  // Output:
  //
  // The size of member a is 1 and its offset is 0.
  // The size of member b is 8 and its offset is 4.
  // The size of member c is 4 and its offset is 12.
  // The size of struct s is 16.
  //
  // The struct s therefore has one hold between members a and b. The memory
  // layout of struct s is therefore as follows:
  //
  // - [byte 0]  char a
  // - [byte 1]  padding                 <----
  // - [byte 2]  padding                 <---- There is a "hole" at these bytes.
  // - [byte 3]  padding                 <----
  // - [byte 4]  int b[2] (element 0)
  // - [byte 5]  int b[2] (element 0)
  // - [byte 6]  int b[2] (element 0)
  // - [byte 7]  int b[2] (element 0)
  // - [byte 8]  int b[2] (element 1)
  // - [byte 9]  int b[2] (element 1)
  // - [byte 10] int b[2] (element 1)
  // - [byte 11] int b[2] (element 1)
  // - [byte 12] float c
  // - [byte 13] float c
  // - [byte 14] float c
  // - [byte 15] float c

  return 0;
}
