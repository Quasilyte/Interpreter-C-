#ifndef EVALUATOR_
#define EVALUATOR_

#include "PtrWalker.hpp"

class Evaluator {
private:
  PtrWalker<char>* byteCode;
  
public:
  void eval(char* input, int len);
};

#endif
