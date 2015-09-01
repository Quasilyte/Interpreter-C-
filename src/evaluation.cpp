#include "evaluation.hpp"

#include <stdio.h>
#include <stdlib.h>

#include "bytecode.hpp"
#include "compilation.hpp"
#include "typeconv.hpp"
#include "util/CstrSlice.hpp"

#define HANDLE(action) case bytecode::action: action(); break

namespace evaluation {
  PtrWalker<uchar>* byteCode; 

  void die() {
    printf("UNEXPECTED BYTE-CODE!\n");
    printf("code: %d\n", byteCode->val());
    exit(1);
  }

  void BC_STOP() {
    printf("found STOP token... stop.\n");
    exit(0);
  }

  void BC_INT() {
    inum val = typeconv::inumBytesToInum(byteCode->head());
    printf("%d\n", val);
    byteCode->move(4);
  }

  void eval() {
    switch (byteCode->valf()) {
      HANDLE(BC_INT);
      HANDLE(BC_STOP);
    default: die(); // Should never happen though
    }
  }
  
  void evalAll() {
    while (byteCode->canMovef()) {
      printf("[%d]\n", byteCode->valf());
    }
  
    byteCode->rewind();
  
    while (byteCode->canMovef()) {
      // We trying to match current (command) byte and
      // moving pointer to make sure handler "sees" only useful byte sequence
      eval();
    }
  }

  void evalRawSources(const char* sources, size_t length) {
    byteCode = compilation::toByteCode(sources, length);
    evalAll(); 
  }
  
  void evalCompiledSources(const uchar* sources) {
  }
}

