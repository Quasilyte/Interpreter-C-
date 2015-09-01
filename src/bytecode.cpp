#include "bytecode.hpp"

#include "typeconv.hpp"

namespace bytecode {
  void appendIntBytes(PtrWalker<uchar>* dest, const char* cstr) {
    dest->setf(BC_INT);
    dest->insertf(typeconv::cstrToInumBytes(cstr), 4);
  }
}
