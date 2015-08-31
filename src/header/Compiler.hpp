#ifndef COMPILER_
#define COMPILER_

#include <string.h>

#include "PtrWalker.hpp"

class Compiler {
private:
  static char* input;
  static PtrWalker<char>* output;

  static void parse();
  static void parseNum();
  static void parseStr();
  static void parseVec();
  
public:
  static PtrWalker<char>* toByteCode(char* input, size_t len);
};

#endif
