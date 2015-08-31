#include "RecurPtrWalker.hpp"

#include <stdlib.h>

#define TMPL_ARGS class T
#define TMPL_TYPENAMES T
#define TMPL_CLASS_NAME RecurPtrWalker
#include "tmpl.hpp"

// We need to use `this' to perform two-phase name lookup.
// In other words, removing `this' will break the compilation.
DTOR() {
  this->rewind();

  for (int i = 0; i < this->cap; ++i) {
    if (*this->p) 
      free(*this->p);
    
    ++this->p;
  }
}

INST(char*);
