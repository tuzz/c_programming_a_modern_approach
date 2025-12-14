#include <stdio.h>
#include <ctype.h>

static float compute_GPA(char grades[], int n) {
  int total = 0;

  for (int i = 0; i < n; i++) {
    switch (toupper(grades[i])) {
      case 'A': total += 4; break;
      case 'B': total += 3; break;
      case 'C': total += 2; break;
      case 'D': total += 1; break;
      default:              break;
    }
  }

  return (float)total / n;
}

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
  char grades[5] = {'a', 'B', 'D', 'F', 'd'};
  printf("GPA: %.2f\n", (double)compute_GPA(grades, ARRAY_COUNT(grades)));
  return 0;
}
