#ifndef EVALUATOR_
#define EVALUATOR_

#include <string.h>

#include "PtrWalker.hpp"

class Evaluator {
private:
  PtrWalker<char>* byteCode;
  
public:
  void eval(char* input, size_t len);
};

#endif
