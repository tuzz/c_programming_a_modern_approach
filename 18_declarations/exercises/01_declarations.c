// Storage classes: auto, static, extern, register
// Type qualifiers: const, volatile
// Type specifiers: type, e.g. unsigned long int
// Declarators: names, preceded by *, followed by [] or ()
// Initializers: expressions, must be constant for static storage

// a) - storage class: static
//    - type qualifier: (none)
//    - type specifier: char
//    - declarator: **lookup(int level)
//    - initializer: (none)
static char **lookup(int level);

// b) - storage class: auto in a block, static at file scope
//    - type qualifier: volatile
//    - type specifier: unsigned long
//    - declarator: io_flags
//    - initializer: (none)
volatile unsigned long io_flags;

// c) - storage class: extern
//    - type qualifier: (none)
//    - type specifier: char
//    - declarators: *file_name[MAX_FILES], path[]
//    - initializer: (none)
extern char *file_name[MAX_FILES], path[];

// d) - storage class: static
//    - type qualifier: const
//    - type specifier: char
//    - declarator: token_buf[]
//    - intializer: ""
static const char token_buf[] = "";

int main(void) {
  return 0;
}

