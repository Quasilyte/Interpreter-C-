#ifndef HEADERS_COMPILATION_
#define HEADERS_COMPILATION_

#include <string.h>

#include "config/types.hpp"
#include "PtrWalker.hpp"

namespace compilation {
  PtrWalker<uchar>* toByteCode(const char* input, size_t length);
}

#endif
