#include <stdio.h>

int main(void) {
  // Here is a loop that uses continue to skip printing the number 5.
  for (int i = 0; i < 10; i++) {
    if (i == 5) { continue; }
    printf("First loop: %d\n", i);
  }

  // Here is an equivalent loop that uses a goto instead of continue.
  for (int i = 0; i < 10; i++) {
    if (i == 5) { goto before_end_of_loop; }
    printf("Second loop: %d\n", i);
    before_end_of_loop: ;
  }

  return 0;
}
