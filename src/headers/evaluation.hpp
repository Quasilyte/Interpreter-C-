#ifndef HEADERS_EVALUATION_
#define HEADERS_EVALUATION_

#include <string.h>

#include "config/types.hpp"

namespace evaluation {
  void evalRawSources(const char* sources, size_t length);
  void evalCompiledSources(const uchar* sources);
}

#endif
