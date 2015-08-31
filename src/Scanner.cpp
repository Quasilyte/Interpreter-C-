#include "header/Scanner.hpp"

#include <ctype.h>

#define CLASS_NAME Scanner 
#include "util/class_codegen.hpp"

DEFN(bool, validDelim(const char c)) noexcept {
  // Closing vector token considered valid delimiter,
  // so expression `430]' is fine, but `430x' is malformed
  return isspace(c) || c == ']';
}
