#ifndef HEADERS_CONFIG_TYPES_
#define HEADERS_CONFIG_TYPES_

#include <stdint.h>

// We use `size_t' when working with <string.h>.

// Types big enough to hold pointer types.
// Should be used in pointer arithmetics and array indexing.
typedef intptr_t addr;
typedef uintptr_t uaddr;

typedef unsigned char uchar; // Avoid something common like `byte'
typedef unsigned int uint;

// Types consumed by the executing language.
// Those can change at some period, thats why we
// need independent typedefs
typedef int32_t inum; // Integral number type
typedef double fnum; // Floating point number type

#endif

