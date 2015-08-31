#include "CstrSlice.hpp"

#define CLASS_NAME CstrSlice
#include "class_codegen.hpp"

CTOR(char* str, int len) {
  pos = len;
  mem = str;
    
  erasedChar = str[len];
  mem[len] = '\0';
}

DTOR() {
  mem[pos] = erasedChar;
}

DEFN(char*, operator char*()) const {
  return mem;
}
