#include "typeconv.hpp"

#include <stdlib.h>
#include <stdio.h>

namespace typeconv {
  inum toInum(const char* cstr) {
    return atoi(cstr);
  }

  char* toCstr(inum v) {
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

  inum inumBytesToInum(uchar* v) {
    return static_cast<inum>(
      v[3] | (v[2] << 8) | (v[1] << 16) | (v[0] << 24)
    );
  }

  uchar* cstrToInumBytes(const char* cstr) {
    inum v = toInum(cstr);
    uchar* bytes = (uchar*) malloc(4);
        
    bytes[0] = (v >> 24) & 0xFF;
    bytes[1] = (v >> 16) & 0xFF;
    bytes[2] = (v >> 8) & 0xFF;
    bytes[3] = v & 0xFF;
    
    return bytes;
  }
}
