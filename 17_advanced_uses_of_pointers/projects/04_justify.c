#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 20

struct node {
  struct node *next;
  char word[];
};

static struct node *line = NULL;
static int line_len = 0;
static int num_words = 0;

static void clear_line(void) {
  for (struct node *p = line, *next; p; p = next) {
    next = p->next;
    free(p);
  }
  line = NULL;
  line_len = 0;
  num_words = 0;
}

static void add_word(const char *word) {
  unsigned long word_len = strlen(word);
  struct node *new_node = calloc(1, sizeof(*new_node) + word_len + 1);

  if (!new_node) {
    printf("Failed to allocate memory.\n");
    exit(EXIT_FAILURE);
  }

  strcpy(new_node->word, word);

  if (line) {
    struct node *p;
    for (p = line; p->next; p = p->next) {}
    p->next = new_node;
  } else {
    line = new_node;
  }

  line_len += word_len;
  if (num_words > 0) {
    line_len++;
  }
  num_words++;
}

static int space_remaining(void) {
  return MAX_LINE_LEN - line_len;
}

static void write_line(void) {
  int extra_spaces, spaces_to_insert, i, j;
  extra_spaces = space_remaining();

  struct node *p = line;
  int count = 0;

  while (p && count < line_len) {
    printf("%s", p->word);

    if (num_words > 1) {
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
    }
    count += strlen(p->word);
    num_words--;
    p = p->next;
  }
  putchar('\n');
}

static void flush_line(void) {
  if (line_len > 0) {
    for (struct node *p = line; p; p = p->next) {
      if (p != line) {
        putchar(' ');
      }
      printf("%s ", p->word);
    }
  }
  printf("\n");
  clear_line();
}

static int read_char(void) {
  int ch = getchar();

  return (ch == '\n' || ch == '\t') ? ' ' : ch;
}

static int read_word(char *word, int len) {
  int ch, pos = 0;

  while ((ch = read_char()) == ' ')
    ;
  while (ch != ' ' && ch != EOF) {
    if (pos < len)
      word[pos++] = (char)ch;
    ch = read_char();
  }
  word[pos] = '\0';
  return pos;
}

int main(void) {
  char word[MAX_WORD_LEN+2];
  int word_len;

  clear_line();
  for (;;) {
    word_len = read_word(word, MAX_WORD_LEN+1);
    if (word_len == 0) {
      flush_line();
      return 0;
    }
    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining()) {
      write_line();
      clear_line();
    }
    add_word(word);
  }
}
