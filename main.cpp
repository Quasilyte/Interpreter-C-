#include "src/header/PtrWalker.hpp"
#include "src/header/RecurPtrWalker.hpp"
#include "src/header/ByteCode.hpp"
#include "src/header/TypeConv.hpp"
#include "src/header/Evaluator.hpp"
#include "src/util/CstrSlice.hpp"
#include "src/util/CstrRange.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <ctype.h>

int main() {
  
  char* str = (char*) malloc(40);
  strcpy(str, "399[301");

  Evaluator ev;
  ev.eval(str, strlen(str));
  
  return 0;
}

