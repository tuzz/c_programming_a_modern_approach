#include <stdio.h>

int count_periods(const char *filename) {
  FILE *fp;
  int n = 0;
  int ch;

  if ((fp = fopen(filename, "r")) != NULL) {
    // The program would incorrectly call fgetc twice which meant that the
    // result of the first call was ignored, effectively skipping every second
    // character in the file. The function would return the wrong result. We can
    // fix it by assigning the result of fgetc to a variable then reuse it.
    while ((ch = fgetc(fp)) != EOF)
      if (ch == '.')
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
