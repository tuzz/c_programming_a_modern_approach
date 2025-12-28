#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define NAME_LEN 25
#define INITIAL_PARTS 10

struct part {
  int number;
  int on_hand;
  char name[NAME_LEN + 1];
  char _padding[2];
};

static struct part *inventory;
static int num_parts = 0;
static int max_parts = INITIAL_PARTS;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
int read_line(char str[], int n);

int main(void) {
  inventory = calloc(10, sizeof(*inventory));
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')
      ;
    switch (code) {
      case 'i': insert();
                break;
      case 's': search();
                break;
      case 'u': update();
                break;
      case 'p': print();
                break;
      case 'q': return 0;
      default: printf("Illegal code\n");
    }
    printf("\n");
  }
}

int find_part(int number) {
  int i;

  for (i = 0; i < num_parts; i++)
    if (inventory[i].number == number)
      return i;
  return -1;
}

void insert(void) {
  int part_number;

  if (num_parts == max_parts) {
    max_parts *= 2;
    struct part *reallocated = realloc(inventory, (unsigned long)max_parts * sizeof(*inventory));

    if (reallocated) {
      printf("Inventory size increased to %d.\n", max_parts);
      inventory = reallocated;
    } else {
      printf("Failed to increase size of inventory.\n");
      return;
    }
  }

  printf("Enter part number: ");
  scanf("%d", &part_number);

  if (find_part(part_number) >= 0) {
    printf("Part already exists.\n");
    return;
  }

  inventory[num_parts].number = part_number;
  printf("Enter part name: ");
  read_line(inventory[num_parts].name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &inventory[num_parts].on_hand);
  num_parts++;
}

void search(void) {
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
  } else {
    printf("Part not found.\n");
  }
}

void update(void) {
  int i, number, change;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    inventory[i].on_hand += change;
  } else
    printf("Part not found.\n");
}

static int order_by_part_number(const void *a, const void *b) {
  const struct part *part1 = (const struct part *)a;
  const struct part *part2 = (const struct part *)b;

  return (*part1).number - (*part2).number;
}

void print(void) {
  int i;

  qsort(inventory, (size_t)num_parts, sizeof(struct part), order_by_part_number);

  printf("Part Number     Part Name                  Quantity on Hand\n");
  for (i = 0; i < num_parts; i++)
    printf("%7d         %-25s%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
}


int read_line(char str[], int n) {
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  while (ch != '\n' && ch != EOF) {
    if (i < n)
      str[i++] = (char)ch;
    ch = getchar();
  }
  str[i] = '\0';
  return i;
}
