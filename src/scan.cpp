#include "scan.hpp"

#include <ctype.h>

namespace scan {
  bool validDelim(const char c) noexcept {
    // Closing vector token considered valid delimiter,
    // so expression `430]' is fine, but `430x' is malformed
    return isspace(c) || c == ']';
  }
}
