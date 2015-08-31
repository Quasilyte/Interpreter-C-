#include "CstrSlice.hpp"

#define CLASS_NAME CstrSlice
#include "class_codegen.hpp"

CTOR(char* cstr, int len) {
  pos = len;
  slice = cstr;
    
  erasedChar = cstr[len];
  slice[len] = '\0';
}

DTOR() {
  slice[pos] = erasedChar;
}

DEFN(, operator char*()) const {
  return slice;
}
