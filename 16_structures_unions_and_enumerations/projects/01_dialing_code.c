#include <stdio.h>

int main(void) {
  struct dialing_code {
    char *country;
    int code;
    char _padding[4];
  };

  const struct dialing_code country_codes[] = {
    { .country ="Argentina", .code = 54 },
    { .country ="Bangladesh", .code = 880 },
    { .country ="Brazil", .code = 55 },
    // ...
  };

  int code;
  printf("Enter dialing code: ");
  scanf("%d", &code);

  for (size_t i = 0; i < sizeof(country_codes) / sizeof(country_codes[0]); i++) {
    if (country_codes[i].code == code) {
      printf("%s\n", country_codes[i].country);
      return 0;
    }
  }

  printf("No country found.\n");
  return 0;
}
