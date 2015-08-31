#include "header/ByteCode.hpp"

#include "header/TypeConv.hpp"

namespace ByteCode {
  void appendIntBytes(PtrWalker<char>* dest, char* cstr) {
    dest->setf(ByteCode::T_INT);
    dest->insertf(TypeConv::cstrToIntBytes(cstr), 4);
  }
}
