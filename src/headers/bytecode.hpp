#ifndef HEADERS_BYTECODE_
#define HEADERS_BYTECODE_

#include "config/types.hpp"
#include "PtrWalker.hpp"

/**
 * Actual identifiers does not matter much,
 * the only thing we need here is to ensure each
 * byte code has the handler with the same name attached.
 * So, the code should not ever "know" what real names are,
 * that is why we mangle names with underscores
 */
// Stop code should ALWAYS be 0
#define BC_STOP bcodeStop__
// Scalar
#define BC_INT bcodeInt__
#define BC_DOUBLE bcodeDouble__
#define BC_STR bcodeStr__
#define BC_VEC bcodeVec__
// Binary Operators
#define BC_ADD bcodeAdd__
#define BC_SUB bcodeSub__

namespace bytecode {
  enum {
    BC_STOP = '\0', // Again, STOP must ALWAYS be 0
    // The order of others not matters
    BC_INT,
    BC_DOUBLE,
    BC_STR,
    BC_VEC,
    BC_ADD,
    BC_SUB
  };

  void appendIntBytes(PtrWalker<uchar>* dest, const char* cstr);
}

#endif
