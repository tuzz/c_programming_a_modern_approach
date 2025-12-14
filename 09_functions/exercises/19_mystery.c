#include <stdio.h>

static void pb(int n) {
  if (n != 0) {
    pb(n / 2);
    putchar('0' + n % 2);
  }
}

// The function prints its input as binary:
//
// pb(19)
//   pb(9)
//     pb(4)
//       pb(2)
//         pb(1)
//           pb(0)
//           putchar('1')     <-- 16
//         putchar('0')       <-- 0
//       putchar('0')         <-- 0
//     putchar('1')           <-- 2
//   putchar('1')             <-- 1
//                               ----
//                         Total: 19

int main(void) {
  int number;
  printf("Enter a number: ");
  scanf("%d", &number);

  printf("Binary: ");
  pb(number);
  putchar('\n');

  return 0;
}
