#include "include/implode.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  size_t size;
  char *data;
  const char **list;
} state;

size_t _len(const char *input) {
  size_t i = 0;
  while (input[i] != '\0') {
    i++;
  }
  return i;
}

void _copy(char *dist, const char *source, size_t len) {
  for (int i = 0; i < len; i++) {
    dist[i] = source[i];
  }
}

char *implode_make(const char **list, const char *separator) {
  if (list == NULL) {
    return NULL;
  }

  state s = {
      .list = list,
      .size = 0,
      .data = NULL,
  };

  const char **pointer = list;

  const char hasSep = separator != NULL;

  size_t sepLen = hasSep ? _len(separator) : 0;

  char *out = NULL;
  size_t i = 0;

  while (s.list[i] != NULL) {
    size_t itemLength = _len(s.list[i]);
    size_t newSize = itemLength + sepLen;
    out = realloc(out, s.size + newSize);
    _copy(out + s.size, s.list[i], itemLength);
    if (hasSep)
      _copy(out + s.size + itemLength, separator, sepLen);
    s.size += newSize;
    i++;
  }

  if (hasSep)
    out[s.size - sepLen] = 0;

  return out;
}

void implode_clean(const char *value) { free(value); }
