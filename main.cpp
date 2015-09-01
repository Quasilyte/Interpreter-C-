#include "PtrWalker.hpp"
#include "RecurPtrWalker.hpp"
#include "bytecode.hpp"
#include "typeconv.hpp"
#include "echo.hpp"
#include "evaluation.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <ctype.h>

int main() {
  echo::message("hi, world!");
  echo::details("%d fmt %s", 500, "string");
  echo::printAsWarning();
  echo::message("this is error text");
  echo::printAsError();
  
  return 0;
}

