#ifndef BYTE_CODE_
#define BYTE_CODE_

namespace ByteCode {
  // `ABORT' should always be 0,
  // actual value of others does not matter at all
  enum {
    ABORT = '\0',
    // Scalars
    T_INT,
    T_DOUBLE,
    T_STR,
    T_VEC,
    // Binary operators
    BIN_OP_ADD,
    BIN_OP_SUB
  };
};

#endif
