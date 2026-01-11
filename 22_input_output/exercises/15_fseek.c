#include <stdio.h>
#include <stdlib.h>

#define ARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

typedef struct {
  char string[64];
} Record;

void print_record_at_seek_position(FILE *stream) {
  Record record;

  if (fread(&record, sizeof(Record), 1, stream) == 1) {
    printf("Record contains the string '%s'\n", record.string);
  } else {
    fprintf(stderr, "Failed to read record n.\n");
    fclose(stream);
    exit(EXIT_FAILURE);
  }
}

int main(void) {
  Record records[4] = {
    { .string = "Here " },
    { .string = "are " },
    { .string = "some " },
    { .string = "records." },
  };

  FILE *fp = fopen("records.dat", "w");
  unsigned long num_written = fwrite(records, sizeof(Record), ARRAY_COUNT(records), fp);

  if (num_written != ARRAY_COUNT(records)) {
    fprintf(stderr, "Failed to write records.dat\n");
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  fclose(fp);
  fp = fopen("records.dat", "rb");
  Record tmp;

  // a) Move to the beginning of record n.
  int n = 2;
  fseek(fp, n * (long)sizeof(Record), SEEK_SET);
  print_record_at_seek_position(fp);

  // b) Move to the beginning of the last record in the file.
  fseek(fp, -(long)sizeof(Record), SEEK_END);
  print_record_at_seek_position(fp);

  // Move to the beginning again.
  fseek(fp, 0, SEEK_SET);

  // c) Move forward one record.
  fseek(fp, (long)sizeof(Record), SEEK_CUR);
  print_record_at_seek_position(fp);

  // d) Move backward two records.
  fseek(fp, -2 * (long)sizeof(Record), SEEK_CUR);
  print_record_at_seek_position(fp);

  fclose(fp);
  return 0;
}


