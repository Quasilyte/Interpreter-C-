#include "compilation.hpp"

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "util/CstrRange.hpp"
#include "util/CstrSlice.hpp"
#include "typeconv.hpp"
#include "bytecode.hpp"
#include "scan.hpp"

namespace compilation {
  const char* input;
  PtrWalker<uchar>* output;
  
  void parseNum() {
    const char *numBegin = input;

    while (isdigit(*++input));
    char c = *input; // Trailing char

    if (c == '.') { // Double
      printf("cant handle doubles\n");
      exit(0);
    } else if (scan::validDelim(c) || (c == 0 && input - numBegin > 1)) {
      bytecode::appendIntBytes(output, numBegin);
    } else {
      printf("malformed num!\n");
      exit(0);
    }

    /*
      CstrRange::ofDigits(&input);
      CstrSlice slice(CstrRange::low, CstrRange::dist());
      bytecode::appendIntBytes(output, static_cast<char*>(slice));
    */
  }

  void parse() {
    char c = *input;
    printf("%c\n", c);

    if (isdigit(c) || c == '-') {
      parseNum();
    } else {
      char *s = (char*) malloc(4); strcpy(s, "111");
      bytecode::appendIntBytes(output, s);
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
      bytecode::appendIntBytes(output, s);
      ++input;
      // parseSym();
      }
    */
  }

  void init(const char* text, size_t length) {
    // Produced bytecode is usually fatter than source code
    output = new PtrWalker<uchar>(length * 3);
  
    // We copy the pointer only and move it until the end.
    // Memory freeing is done outside.
    input = text;
  }

  void parseInput() {
    while(*input) { // Pointer is moved inside parsing methods
      parse();
    }
  }

  PtrWalker<uchar>* toByteCode(const char* text, size_t length) {
    init(text, length);
  
    parseInput();

    return output;
  }
}
