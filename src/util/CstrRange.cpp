#include "CstrRange.hpp"

#include <ctype.h>

#define CLASS_NAME CstrRange
#include "class_codegen.hpp"

// Declare class static members
char* CLASS_NAME::low;
char* CLASS_NAME::high;

// To avoid both code duplication and inderect calls
#define MOVE(cstr, ...)				\
  load(cstr);					\
  __VA_ARGS__;					\
  *cstr = high; 

DEFN(void, load(char** cstr)) {
  low = high = *cstr;
}

DEFN(void, ofDigits(char** cstr)) {
  MOVE(cstr, while (isdigit(*++high)));
}

DEFN(int, dist()) {
  return high - low;
}
