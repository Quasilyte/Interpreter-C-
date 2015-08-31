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
#include "header/Scanner.hpp"

char* CLASS_NAME::input;
PtrWalker<unsigned char>* CLASS_NAME::output;

// "-4354.5"
// "455"
// "355.6"

DEFN(void, parseNum()) {
  char *numBegin = input;

  while (isdigit(*++input));
  char c = *input; // Trailing char

  if (c == '.') { // Double
    printf("cant handle doubles\n");
    exit(0);
  } else if (Scanner::validDelim(c) || (c == 0 && input - numBegin > 1)) {
    ByteCode::appendIntBytes(output, numBegin);
  } else {
    printf("malformed num!\n");
    exit(0);
  }

  /*
  CstrRange::ofDigits(&input);
  CstrSlice slice(CstrRange::low, CstrRange::dist());
  ByteCode::appendIntBytes(output, static_cast<char*>(slice));
  */
}

DEFN(void, parse()) {
  char c = *input;
  printf("%c\n", c);

  if (isdigit(c) || c == '-') {
    parseNum();
  } else {
    char *s = (char*) malloc(4); strcpy(s, "111");
    ByteCode::appendIntBytes(output, s);
    ++input;
  }
  
  /*
  if (isdigit(c) || c == '-') {
    parseNum();
  } else if (c == '[') {
    ++input; 
    // parseVec();
  } else if (c == '\'') {
    // parseStr();
  } else {
    char *s = (char*) malloc(4); strcpy(s, "111");
    ByteCode::appendIntBytes(output, s);
    ++input;
    // parseSym();
  }
  */
}

DEFN(PtrWalker<unsigned char>*, toByteCode(char* text, size_t len)) {
  output = new PtrWalker<unsigned char>(len + len + len);
  input = text;
  
  while(*input) {
    parse();
  }

  output->rewind();
  return output;
}
