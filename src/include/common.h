#ifndef COMMON_H
#define COMMON_H
#include <stddef.h>

#if defined(__cplusplus)
#define BEGIN_DECL   extern "C" {
#define END_DECL     }
#else
#define BEGIN_DECL
#define END_DECL
#endif

#endif //COMMON_H
