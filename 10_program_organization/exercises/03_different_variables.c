static int i = 0;

int main(void) {
  int i = 1;

  for (int i = 0; i < 10; i ++) {

  }

  {
    int i = 123;
  }

  {
    int i = 456;
  }
}

// A program that only has one function (main) could contain an infinite number
// of different variables named i because it can appear in multiple block scopes.
