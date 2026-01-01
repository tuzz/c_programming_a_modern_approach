int main(void) {
  // The answer is a). If a variables storage duration is static then they will
  // be initialized to their default value which is 0 for arithmetic types and
  // NULL for pointers, which are often represented by zeroed out bits, anyway.
  static int a;

  return 0;
}
