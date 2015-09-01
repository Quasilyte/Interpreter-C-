#ifndef HEADERS_TYPECONV_
#define HEADERS_TYPECONV_

#include <stdint.h>

#include "config/types.hpp"

namespace typeconv {
  inum toInum(const char* cstr);
  char* toCstr(inum v);

  inum inumBytesToInum(uchar* v);
  uchar* cstrToInumBytes(const char* cstr);
}

#endif
