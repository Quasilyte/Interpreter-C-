#ifndef HEADER_TYPE_CONV_
#define HEADER_TYPE_CONV_

#include <stdint.h>

#include "platform_specific/endians.hpp"

namespace TypeConv {
  int32_t toInt(char* v);
  char* toCstr(int32_t v);

  int32_t intBytesToInt(unsigned char* v);
  unsigned char* cstrToIntBytes(char* s);
}

#endif
