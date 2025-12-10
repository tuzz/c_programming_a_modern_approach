#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int age = 15;
  bool teenager = false;

  if (age >= 13)
    if (age <= 19)
      teenager = true;
    else
      teenager = false;
  else if (age < 13)
    teenager = false;

  printf("age:%d\n", age);
  printf("teenager:%d\n", teenager);

  // Simplified:
  teenager = age >= 13 && age <= 19;
  printf("age:%d\n", age);
  printf("teenager:%d\n", teenager);

  return 0;
}
