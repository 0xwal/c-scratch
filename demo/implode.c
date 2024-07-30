#include <explode.h>
#include <implode.h>
#include <stdio.h>

int main() {
  explode_s list = explode_make("hello world hello C", ' ');

  const char *value = implode_make((const char **)list.values, "<=>");

  printf("output: %s\n", value);

  implode_clean((char *)value);

  explode_clean(&list);
}
