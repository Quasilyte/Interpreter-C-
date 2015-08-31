#ifndef COMPILER_
#define COMPILER_

#include "PtrWalker.hpp"

class Compiler {
private:
  static char* input;
  static PtrWalker<char>* output;

  void parse();
  void parseNum();
  void parseStr();
  void parseVec();
  
public:
  static PtrWalker<char>* toByteCode(char* input);
};

#endif
