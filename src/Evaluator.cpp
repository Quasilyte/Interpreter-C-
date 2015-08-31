#include "Evaluator.hpp"

#include <string.h>
#include <stdio.h>

#include "Compiler.hpp"
#include "ByteCode.hpp"
#include "typeconv.hpp"

void Evaluator::eval(char* input, int len) {
  // byteCode = Compiler::toByteCode(input);
  byteCode = new PtrWalker<char>(input, len);

  for (int i =  0; !byteCode->atEnd(); ++i) {
    switch (byteCode->valf()) {
    case ByteCode::T_INT:
      printf("%d\n", intBytesToInt(byteCode->getHead()));
      byteCode->move(4);
      break;
    default:
      printf("skipping `%c'\n", byteCode->val());
    }
  }
}
