#ifndef HEADER_EVALUATOR_
#define HEADER_EVALUATOR_

#include <string.h>

#include "PtrWalker.hpp"
#include "MultiStack.hpp"
#include "ByteCode.hpp"

class Evaluator {
private:
  static PtrWalker<unsigned char>* byteCode;;

  static void die();
  static void BC_STOP();
  static void BC_INT();
  
public:
  static void eval(char* input, size_t len);
};

#endif
