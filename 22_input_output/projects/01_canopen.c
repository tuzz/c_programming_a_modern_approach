#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
  FILE *fp;

  if (argc < 2) {
    printf("usage: canopen filenames\n");
    exit(EXIT_FAILURE);
  }

  bool success = true;

  for (int i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "r")) == NULL) {
      printf("%s can't be opened\n", argv[i]);
      success = false;
    } else {
      printf("%s can be opened\n", argv[i]);
      fclose(fp);
    }
  }

  if (success) {
    return 0;
  } else {
    exit(EXIT_FAILURE);
  }
}
