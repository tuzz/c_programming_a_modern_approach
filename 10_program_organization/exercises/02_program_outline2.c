int b, c;

void f(void) {
  int b, d;
  // a) Visible in this scope: b, c, d
  //    - b is from block scope (line 4) rather than file scope (line 1)
}

void g(int a) {
  int c;
  {
    int a, d;
    // c) Visible in this scope: a, b, c, d
    //    - a is from block scope (line 12) rather than function parameter (line 9)
    //    - c is from block scope (line 10) rather than file scope (line 1)
  }
  // b) Visible in this scope: a, b, c
  //    - c is from block scope (line 10) rather than file scope (line 1)
}

int main(void) {
  int c, d;
  // d) Visible in this scope: b, c, d
  //    - c is from block scope (line 22) rather than file scope (line 1)
}
