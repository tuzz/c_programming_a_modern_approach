#include <stdio.h>

int main(void) {
  char *filename = "something";
  FILE *fp;

  if ((fp = fopen(filename, "r"))) {
    // read characters until end-of-file

    fclose(fp); // <-- This line needs to be inside the block because fclose
                //     must take an argument that is a file opened with fopen.
  }

  return 0;
}
