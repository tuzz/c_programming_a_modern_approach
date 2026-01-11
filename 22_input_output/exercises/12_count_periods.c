#include <stdio.h>

int count_periods(const char *filename) {
  FILE *fp;
  int n = 0;

  if ((fp = fopen(filename, "r")) != NULL) {
    while (fgetc(fp) != EOF)
      if (fgetc(fp) == '.')
        n++;
    fclose(fp);
  }

  return n;
}

int main(void) {
  int n = count_periods("22_input_output/exercises/12_count_periods.c");
  printf("There are %d periods in this file.\n", n);
  return 0;
}
