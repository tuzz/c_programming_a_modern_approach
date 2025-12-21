#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

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

static bool test_extension(const char *file_name, const char *extension) {
  char file_extension[10] = "";
  get_extension(file_name, file_extension);

  for (const char *p = file_extension; *p; p++) {
    if (toupper(*p) != toupper(*extension)) { return false; }
    extension++;
  }

  return *extension == '\0';
}

int main(void) {
  printf("0: %s\n", test_extension("memo.txt", "txt") ? "true" : "false");
  printf("1: %s\n", test_extension("memo.txt", "TXT") ? "true" : "false");
  printf("2: %s\n", test_extension("memo.a.b.c.txt", "TXT") ? "true" : "false");
  printf("3: %s\n", test_extension("memo.txt", "TXTZ") ? "true" : "false");
  printf("4: %s\n", test_extension("memo.txtz", "TXT") ? "true" : "false");
  return 0;
}
