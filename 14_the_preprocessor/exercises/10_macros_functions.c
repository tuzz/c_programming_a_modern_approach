int main(void) {
  // Macros are not suitable if their arguments have side effects, such as i++
  // since the macro evaluates the side effects multiple times which introduces bugs.
  // Furthermore, it might result in undefined behaviour if they are unsequenced, e.g.
  // if we call a DOUBLE macro with x++ that is defined as ((x) + (x)).
  //
  // Macros don't expand themselves so they are not suitable for recursive functions.
  //
  // Macros can't be referenced as a function pointer which makes them unsuitable
  // when we need to pass a function pointer to a block of executable code.

  return 0;
}
