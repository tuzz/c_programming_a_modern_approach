extern float a; // static duration, file scope, external linkage

void f(
  register double b // automatic duration, block scope, no linkage
) {
  static int c; // static duration, block scope, no linkage
  auto char d; // automatic duration, block scope, no linkage
}
