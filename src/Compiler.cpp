#include "header/Compiler.hpp"

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define CLASS_NAME Compiler
#include "util/class_codegen.hpp"

#include "util/CstrRange.hpp"
#include "util/CstrSlice.hpp"
#include "header/TypeConv.hpp"
#include "header/ByteCode.hpp"

char* CLASS_NAME::input;
PtrWalker<unsigned char>* CLASS_NAME::output;

DEFN(void, parseNum()) {
  CstrRange::ofDigits(&input);
  CstrSlice slice(CstrRange::low, CstrRange::dist());
  ByteCode::appendIntBytes(output, static_cast<char*>(slice));
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
    char *s = (char*) malloc(4); strcpy(s, "111");
    ByteCode::appendIntBytes(output, s);
    
    // parseSym();
  }
}

DEFN(PtrWalker<unsigned char>*, toByteCode(char* text, size_t len)) {
  output = new PtrWalker<unsigned char>(len + len);

  for (input = text; *input; ++input)
    parse();

  output->rewind();
  return output;
}
