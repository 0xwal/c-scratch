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
  // if (values_pointer == NULL) {
  //   return malloc(values_pointer);
  // }
  return realloc(values_pointer, sizeof(char *) * size);
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
      char *spaceForOccurance = malloc(NSIZE(chunkLength));
      e.values = _extend_values(e.values, e.count + 1);
      e.values[i] = spaceForOccurance;
      copy(e.values[i], chunkStart, chunkLength);
      e.values[i][chunkLength] = 0;
      chunkStart = textPointer + 1;
      e.count++;
      i++;
    }
    textPointer++;
  }

  if (i > 0) {
    size_t chunkLength = textPointer - chunkStart;
    e.values = _extend_values(e.values, e.count + 1);
    e.values[i] = malloc(NSIZE(chunkLength));
    copy(e.values[i], chunkStart, chunkLength);
    e.values[i][chunkLength] = 0;
    e.count++;
  }

  return e;
}

void explode_clean(explode_s *exp) {
  for (int i = 0; i < exp->count; ++i) {
    free(exp->values[i]);
  }
  free(exp->values);
}
