#include <stdio.h>

int main(void) {
  char *s1 = "Hello, your sales rank is #989.";
  char *s2 = "Hello, your sales rank is #24,675.";
  char *s3 = "Hello, your sales rank is #1,162,620.";

  char sales_rank[100];

  if (sscanf(s1, "%*[^#]#%[0123456789,]", sales_rank) == 1) {
    printf("Sales rank: %s\n", sales_rank);
  } else {
    printf("Failed to read sales rank.\n");
  }

  if (sscanf(s2, "%*[^#]#%[0123456789,]", sales_rank) == 1) {
    printf("Sales rank: %s\n", sales_rank);
  } else {
    printf("Failed to read sales rank.\n");
  }

  if (sscanf(s3, "%*[^#]#%[0123456789,]", sales_rank) == 1) {
    printf("Sales rank: %s\n", sales_rank);
  } else {
    printf("Failed to read sales rank.\n");
  }

  return 0;
}
