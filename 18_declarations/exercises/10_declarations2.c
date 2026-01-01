// a) p is a pointer to a function with a character pointer argument that returns a character pointer.
static char *(*p)(char *);

// b) f is a function with two arguments: p, a pointer to a structure with tag t, and n, a long integer.
// f returns a pointer to a function that has no arguments and returns nothing.
struct t { int x; };
static void (*f(struct t *p, long n))(void);

// c) a is an array of four pointers to functions that have no arguments and return nothing.
// The elements of a intially point to functions named insert, search, update and print.
static void insert(void) {}
static void search(void) {}
static void update(void) {}
static void print(void) {}
static void (*a[4])(void) = {insert, search, update, print};

// d) b is an array of 10 pointers to functions with two int arguments that return structures with tag t.
static struct t (*b[10])(int, int);

int main(void) {
  return 0;
}
