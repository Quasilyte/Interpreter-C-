#include "Compiler.hpp"

#include <ctype.h>
#include <string.h>

#define CLASS_NAME Compiler
#include "util/class_codegen.hpp"

// NUM: 4 byte encoded int32_t
// STR: 4 byte length, N bytes - str contents
// VEC: 4 byte length, N pointers to code

DEFN(void, parseNum()) {
  const char* slice = input;

  while (isdigit(*++input)) {
  }

  char tmp = *input;
  *input = '\0';
  output.insert(slice, 4);
  *input = tmp;
}

DEFN(void, parse()) {
  char c = *input;
  
  if (isdigit(c) || c == '-') {
    parseNum();
  } else if (c == '[') {
    // parseVec();
  } else if (c == '\'') {
    // parseStr();
  } else {
    // parseSym();
  }
}

DEFN(char*, toByteCode(char* text, size_t len)) {
  output = new PtrWalker<char>(len + len);

  for (input = text; *input; ++input) {
    parse();
  }
}
