#include <stdio.h>
#include <string.h>

static void get_extension(const char *file_name, char *extension) {
  size_t len = strlen(file_name);
  const char *copy_from = file_name + len;

  for (const char *p = file_name; p < file_name + len; p++) {
    if (*p == '.') {
      copy_from = p + 1;
    }
  }

  strcpy(extension, copy_from);
}

int main(void) {
  char extension[10] = "";

  get_extension("memo.txt", extension);
  printf("%s\n", extension);

  get_extension("memo.a.b.c.txt", extension);
  printf("%s\n", extension);

  get_extension("cat.jpg", extension);
  printf("%s\n", extension);

  return 0;
}
