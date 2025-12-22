#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// For convenience, all the code is in one file rather than splitting it as per
// the book and setting up another Makefile. We already did that last exercise
// so I don't think we need to do it again. The exercises don't relate to that.

#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 20

static char line[MAX_LINE_LEN+1];
static int line_len = 0;
static int num_words = 0;

static void clear_line(void) {
  line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

static void add_word(const char *word) {
  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len+1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}

static int space_remaining(void) {
  return MAX_LINE_LEN - line_len;
}

static void write_line(int line_number) {
  int extra_spaces, spaces_to_insert, i, j;
  bool is_odd_line = line_number % 2 == 1;

  extra_spaces = MAX_LINE_LEN - line_len;
  for (i = 0; i < line_len; i++) {
    if (line[i] != ' ')
      putchar(line[i]);
    else {
      if (is_odd_line) {
        spaces_to_insert = extra_spaces / (num_words - 1);
      } else {
        spaces_to_insert = (extra_spaces + num_words - 2) / (num_words - 1);
      }
      for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }
  putchar('\n');
}

static void flush_line(void) {
  if (line_len > 0)
    puts(line);
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
    if (pos <= len)
      word[pos++] = (char)ch;
    ch = read_char();
  }
  if (pos == len + 1) {
    word[len] = '*';
  }
  word[pos] = '\0';
  return pos;
}

int main(void) {
  char word[MAX_WORD_LEN+2];
  int word_len;
  int line_number = 1;

  clear_line();
  for (;;) {
    word_len = read_word(word, MAX_WORD_LEN);
    if (word_len == 0) {
      flush_line();
      return 0;
    }
    if (word_len + 1 > space_remaining()) {
      write_line(line_number++);
      clear_line();
    }
    add_word(word);
  }
}
