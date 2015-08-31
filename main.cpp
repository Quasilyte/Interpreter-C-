#include "src/PtrWalker.hpp"
#include "src/RecurPtrWalker.hpp"
#include "src/ByteCode.hpp"
#include "src/typeconv.hpp"
#include "src/Evaluator.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

int main() {
  Evaluator evaluator;
  char s[] = {'a', 'b', 1, 0, 0, 0, 6, 'z', 'v'};
  evaluator.eval(s, 8);
  
  return 0;
}

