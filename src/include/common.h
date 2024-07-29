#ifndef COMMON_H
#define COMMON_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define NSIZE(s) (s + 1)

#if defined(__cplusplus)
#define BEGIN_DECL extern "C" {
#define END_DECL }
#else
#define BEGIN_DECL
#define END_DECL
#endif

#endif // COMMON_H
