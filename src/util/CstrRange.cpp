#include "CstrRange.hpp"

#include <ctype.h>

#define CLASS_NAME CstrRange
#include "class_codegen.hpp"

// Declare static members
char* CLASS_NAME::low;
char* CLASS_NAME::high;

DEFN(void, load(char* cstr)) {
  low = high = cstr;
}

DEFN(void, ofDigits(char* cstr)) {
  load(cstr);
  
  while (isdigit(*++high));
}

DEFN(int, dist()) {
  return high - low;
}
