#include "header/ByteCode.hpp"

#include "header/TypeConv.hpp"
#include <stdio.h>

namespace ByteCode {
  void appendIntBytes(PtrWalker<unsigned char>* dest, char* cstr) {
    dest->setf(BC_INT);
    dest->insertf(TypeConv::cstrToIntBytes(cstr), 4);
  }
}
