#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void new_cmd(void)       { printf("called new_cmd\n"); }
static void open_cmd(void)      { printf("called open_cmd\n"); }
static void close_cmd(void)     { printf("called close_cmd\n"); }
static void close_all_cmd(void) { printf("called close_all_cmd\n"); }
static void save_cmd(void)      { printf("called save_cmd\n"); }
static void save_as_cmd(void)   { printf("called save_as_cmd\n"); }
static void save_all_cmd(void)  { printf("called save_all_cmd\n"); }
static void print_cmd(void)     { printf("called print_cmd\n"); }
static void exit_cmd(void)      { printf("called exit_cmd\n"); }

typedef struct {
  char *cmd_name;
  void (*cmd_pointer)(void);
} Command;

static void call(char *name, Command *commands, int n) {
  for (int i = 0; i < n; i++) {
    if (strcmp(commands[i].cmd_name, name) == 0) {
      commands[i].cmd_pointer();
      return;
    }
  }

  printf("invalid command: %s\n", name);
  exit(1);
}

int main(void) {
  Command file_cmd[] = {
    {"new",       new_cmd},
    {"open",      open_cmd},
    {"close",     close_cmd},
    {"close_all", close_all_cmd},
    {"save",      save_cmd},
    {"save as",   save_as_cmd},
    {"save all",  save_all_cmd},
    {"print",     print_cmd},
    {"exit",      exit_cmd},
  };

  call("open", file_cmd, sizeof(file_cmd) / sizeof(file_cmd[0]));
  call("close_all", file_cmd, sizeof(file_cmd) / sizeof(file_cmd[0]));
  call("print", file_cmd, sizeof(file_cmd) / sizeof(file_cmd[0]));
  call("delete", file_cmd, sizeof(file_cmd) / sizeof(file_cmd[0]));

  return 0;
}
