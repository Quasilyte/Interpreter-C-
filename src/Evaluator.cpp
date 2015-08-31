#include "header/Evaluator.hpp"

#include <stdio.h>
#include <stdlib.h>

#include "header/Compiler.hpp"
#include "header/TypeConv.hpp"
#include "util/CstrSlice.hpp"

#define CLASS_NAME Evaluator
#include "util/class_codegen.hpp"

#define HANDLE(action) case ByteCode::action: action(); break

PtrWalker<unsigned char>* CLASS_NAME::byteCode; 

DEFN(void, eval(char* input, size_t len)) {
  byteCode = Compiler::toByteCode(input, len);

  while (byteCode->canMovef()) {
    printf("[%d]\n", byteCode->valf());
  }
  
  byteCode->rewind();
  
  while (byteCode->canMovef()) {
    // We trying to match current (command) byte and
    // moving pointer to make sure handler "sees" only useful byte sequence
    switch (byteCode->valf()) {
      HANDLE(BC_INT);
      HANDLE(BC_STOP);
    default: die(); // Should never happen though
    }
  }
}

DEFN(void, die()) {
  printf("UNEXPECTED BYTE-CODE!\n");
  printf("code: %d\n", byteCode->val());
  exit(1);
}

DEFN(void, BC_STOP()) {
  printf("found STOP token... stop.\n");
  exit(0);
}

DEFN(void, BC_INT()) {
  int32_t val = TypeConv::intBytesToInt(byteCode->head());
  printf("%d\n", val);
  byteCode->move(4);
}
