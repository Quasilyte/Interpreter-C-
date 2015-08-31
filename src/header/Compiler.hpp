#ifndef HEADER_COMPILER_
#define HEADER_COMPILER_

#include <string.h>

#include "PtrWalker.hpp"

class Compiler {
private:
  static char* input;
  static PtrWalker<unsigned char>* output;

  static void parse();
  static void parseNum();
  static void parseStr();
  static void parseVec();
  
public:
  static PtrWalker<unsigned char>* toByteCode(char* input, size_t len);
};

#endif
