#include <stdio.h>

int main(void) {
  int score = 75;

  // if statement 1:
  if (score >= 90)
    printf("A\n");
  else if (score >= 80)
    printf("B\n");
  else if (score >= 70)
    printf("C\n");
  else if (score >= 60)
    printf("D\n");
  else
    printf("F\n");

  // if statement 2:
  if (score < 60)
    printf("F\n");
  else if (score < 70)
    printf("D\n");
  else if (score < 80)
    printf("C\n");
  else if (score < 90)
    printf("B\n");
  else
    printf("A\n");

  // Yes, the if statements are equivalent since < is the opposite of >= and
  // both conditionals cover the full domain of integer scores.

  return 0;
}
