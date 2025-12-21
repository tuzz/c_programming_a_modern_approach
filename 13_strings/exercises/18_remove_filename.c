#include <stdio.h>

static void remove_filename(char *url) {
  char *last_slash = url;

  for (char *p = url; *p; p++) {
    if (*p == '/') {
      last_slash = p;
    }
  }

  *last_slash = '\0';
}

int main(void) {
  char url[] = "http://www.knking.com/index.html";

  remove_filename(url);
  printf("%s\n", url);

  return 0;
}
