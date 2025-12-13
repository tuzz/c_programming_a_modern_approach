#include <stdio.h>

int main(void) {
  int number;
  printf("Enter a positive integer: ");
  scanf("%d", &number);

  long double factorial = 1.0;
  for (int i = 2; i <= number; i++) {
    factorial *= i;
    // printf("%d: %Lf\n", i, factorial);
  }

  // a) 7 is the largest because 8! = 40,320 which is greater than 2^15 - 1
  // b) 12 is the largest because 13! = 6,227,020,800 which is larger than 2^31 - 1
  // c) 20 is the largest because 21! = 2,432,902,008,176,640,000 which is larger than 2^63 - 1
  // d) 20 is the largest because 21! = 2,432,902,008,176,640,000 which is larger than 2^63 - 1
  // d) 34 is the largest because 35! = 1.03331e40 which is larger than 3.40282e38
  // e) 170 is the largest because 171! = 1.24102e309 which is larger than 1.79769e308
  // f) 170 is the largest because 171! = 1.24102e309 which is larger than 1.79769e308

  printf("Factorial of %d: %Lf\n", number, factorial);
  return 0;
}
