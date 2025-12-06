int main(void) {
  // a) Not legal because identifiers can't start with digits.
  // int 100_bottles;

  // b) Legal because identifiers can start with underscores.
  int _100_bottles;

  // c) Legal.
  int one__hundred__bottles;

  // d) Legal
  int bottles_by_the_hundred_;

  return 0;
}
