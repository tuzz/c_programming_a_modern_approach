enum foo { A };
struct bar { int x; };
union baz { int x; float y; };

int main(void) {
  // a) array variables can be initialized:
  int a[3] = {1, 2, 3};

  // b) enumeration variables can be initialized:
  enum foo f = A;

  // c) structure variables can be initialized:
  struct bar b = {0};

  // d) union variables can be initialized:
  union baz z = {0};

  // Therefore, the answer is e) None of the above.

  return 0;
}
