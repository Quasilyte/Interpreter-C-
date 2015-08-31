#include "header/Compiler.hpp"

#include <ctype.h>
#include <string.h>

#define CLASS_NAME Compiler
#include "util/class_codegen.hpp"

#include "util/CstrRange.hpp"
#include "util/CstrSlice.hpp"
#include "header/TypeConv.hpp"
#include "header/ByteCode.hpp"

char* CLASS_NAME::input;
PtrWalker<char>* CLASS_NAME::output;

DEFN(void, parseNum()) {
  CstrRange::ofDigits(input);
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
    // parseSym();
  }
}

DEFN(PtrWalker<char>*, toByteCode(char* text, size_t len)) {
  output = new PtrWalker<char>(len + len);

  for (input = text; *input; ++input)
    parse();

  output->rewind();
  return output;
}
