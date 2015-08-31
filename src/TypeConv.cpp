#include "header/TypeConv.hpp"

#include <stdlib.h>

namespace TypeConv {
  int32_t toInt(char* v) {
    return atol(v);
  }

  char* toCstr(int32_t v) {
    static char bag[10];
    static int i;
    static int j;
    bool negate = false;

    if (v < 0) {
      negate = true;
      v = -v;
    }
  
    for (i = 0; v; v /= 10, ++i) {
      bag[i] = v % 10 + '0';
    }

    if (negate) {
      bag[i++] = '-';
    }
  
    char* s = (char*) calloc(i + 2, 1);

    for (j = 0; i; ++j) {
      s[j] = bag[--i];
    }
  
    return s;
  }

  int32_t intBytesToInt(char* v) {
    return static_cast<int32_t>(
      v[3] | (v[2] << 8) | (v[1] << 16) | (v[0] << 24)
    );
  }

  char* cstrToIntBytes(char* s) {
    int32_t v = toInt(s);

    char *bytes = (char*) malloc(4);
    bytes[0] = (v >> 24) & 0xFF;
    bytes[1] = (v >> 16) & 0xFF;
    bytes[2] = (v >> 8) & 0xFF;
    bytes[3] = v & 0xFF;

    return bytes;
  }
}
