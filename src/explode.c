//
// Created by 0xWaleed on 11/8/2021.
//

#include "include/explode.h"
#include "common.h"
#include <stdlib.h>

void copy(char *dist, const char *source, size_t length) {
  for (int i = 0; i < length; ++i) {
    dist[i] = source[i];
  }
}

char **_extend_values(char **values_pointer, size_t size) {
  return realloc(values_pointer, sizeof(char *) * size);
}

void _append_to_list(explode_s *e, char *occurence, size_t position,
                     size_t length) {
  e->values = _extend_values(e->values, e->count + 1);
  char *spaceForOccurance = malloc(NSIZE(length));
  e->values[position] = spaceForOccurance;

  copy(e->values[position], occurence, length);
  e->values[position][length] = 0;
}

explode_s explode_make(const char *text, char character) {
  explode_s e = {0};

  e.count = 0;

  const char *textPointer = text;
  const char *chunkStart = text;
  size_t i = 0;

  while (*textPointer != '\0') {
    if (*textPointer == character) {
      size_t chunkLength = textPointer - chunkStart;
      _append_to_list(&e, (char *)chunkStart, i, chunkLength);
      chunkStart = textPointer + 1;
      e.count++;
      i++;
    }
    textPointer++;
  }

  // last occurrence
  if (i > 0) {
    size_t chunkLength = textPointer - chunkStart;
    _append_to_list(&e, (char *)chunkStart, i, chunkLength);
    e.count++;
  }

  e.values = _extend_values(e.values, e.count + 1);
  e.values[e.count] = NULL;

  return e;
}

void explode_clean(explode_s *exp) {
  for (int i = 0; i < exp->count; ++i) {
    free(exp->values[i]);
  }
  free(exp->values);
}
