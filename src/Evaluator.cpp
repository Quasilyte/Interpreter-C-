#include "header/Evaluator.hpp"

#include <stdio.h>

#include "header/Compiler.hpp"
#include "header/ByteCode.hpp"
#include "header/TypeConv.hpp"

void Evaluator::eval(char* input, size_t len) {
  byteCode = Compiler::toByteCode(input, len);
  
  //for (int i =  0; !byteCode->atEnd(); ++i) {
    switch (byteCode->valf()) {
    case ByteCode::T_INT:
      printf("%d\n", TypeConv::intBytesToInt(byteCode->head()));
      byteCode->move(3);
      break;
    default:
      printf("code: %d\n", byteCode->val());
      printf("skipping `%c'\n", byteCode->val());
    }
    //}
}
