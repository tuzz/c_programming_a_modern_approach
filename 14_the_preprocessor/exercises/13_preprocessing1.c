// Included lines from stdio.h

void f(void);

int main(void)
{
  f();
  return 0;
}

void f(void)
{
  printf("N is undefined\n");
}


// The output of this program will therefore be "N is undefined\n"
